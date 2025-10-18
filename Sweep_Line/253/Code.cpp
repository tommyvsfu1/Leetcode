class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        vector<pair<int,int>> q;
        for (int i = 0; i < intervals.size(); i++) {
            q.push_back({intervals[i][0],1});
            q.push_back({intervals[i][1],-1});
        }

        sort(q.begin(), q.end());

        int res = 0;
        int count = 0;
        for (int i = 0; i < q.size(); i++) {
            count += q[i].second;
            res = max(res, count);
        }
        
        return res;
    }
};
