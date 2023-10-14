class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, int> mp;

        unordered_map<int, vector<pair<int,int>>> graph;
        for (auto &t : times) {
            int u = t[0];
            int v = t[1];
            int w = t[2];
            graph[u].push_back({w,v});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0,k});
        int res = 0;
        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (mp.find(u) != mp.end()) continue;
            
            mp[u] = d;
            
            res = max(res, d);

            for (auto next : graph[u]) {
                if (mp.find(next.second) != mp.end()) continue;
                pq.push({next.first+d, next.second});
            }
        }

        if (mp.size() != n) return -1;

        return res;
    }
};