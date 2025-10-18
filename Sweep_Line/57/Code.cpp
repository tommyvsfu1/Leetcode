class Solution {
    static bool cmp(pair<int,int>& a, pair<int,int>& b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        else {
            return a.first < b.first;
        }
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<pair<int,int>> q;

        for (int i = 0; i < intervals.size(); i++) {
            q.push_back({intervals[i][0], 1});
            q.push_back({intervals[i][1], -1});
        }
        q.push_back({newInterval[0], 1});
        q.push_back({newInterval[1], -1});

        sort(q.begin(), q.end(), cmp);

        int count = 0;
        int start = -1;
        int end = -1;
        vector<vector<int>> res;
        for (int i = 0; i < q.size(); i++) {
            if (start == -1) {
                start = q[i].first;
            }
            
            count += q[i].second;

            if (count == 0) {
                end = q[i].first;
                res.push_back({start,end});
                start = -1;
                end = -1;
            }
        }

        return res;
    }
};
