class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        for (int i = 0; i < logs.size(); i++)
            logs[i] = {logs[i][1], logs[i][0]}; // time , id
        
        sort(logs.begin(), logs.end());

        vector<vector<int>> q;
        for (int i = 0; i < queries.size(); i++)
            q.push_back({queries[i], i}); // time, query index
        
        sort(q.begin(), q.end());

        int j = 0, i = 0;
        vector<int> res(queries.size());
        unordered_map<int, int> mp;

        for (auto& qq : q) {
            int t = qq[0];
            int idx = qq[1];

            while(j < logs.size() && logs[j][0] <= t) {
                mp[logs[j][1]]++;
                j++;
            }

            while (i < logs.size() && logs[i][0] < t-x) {
                mp[logs[i][1]]--;
                if (mp[logs[i][1]] == 0)
                    mp.erase(logs[i][1]);
                i++;
            }
            res[idx] = n - mp.size();
        }
        return res;
    }
};