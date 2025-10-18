class Solution {
    static bool cmp(pair<int,int>& a, pair<int,int>& b) {
        if (a.first != b.first) {
            return a.first < b.first;
        }
        else {
            return a.second > b.second;
        }
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int,int>> q;

        for (int i = 0; i < intervals.size(); i++) {
            q.push_back({intervals[i][0],1});
            q.push_back({intervals[i][1],-1});
        }

        sort(q.begin(), q.end(), cmp);

        vector<vector<int>> res;
        int count = 0;
        int start = 0;
        int end = 0;
        for (int i = 0; i < q.size(); i++) {

            if ((count == 0) && (q[i].second > 0) ) {
                start = q[i].first;
            }
            else if ((count > 0) && (count + q[i].second == 0)) {
                end = q[i].first;
                res.push_back({start,end});
            }
            count += q[i].second;
        }
        return res;
    }
};
