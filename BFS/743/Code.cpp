class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> neighbors(n, vector<pair<int,int>>());

        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0] - 1;
            int v = times[i][1] - 1;
            int w = times[i][2];
            neighbors[u].push_back({w, v});
        }

        vector<int> visited(n, 0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        int res = 0;
        pq.push({0, k-1});
        while (!pq.empty()) {
            auto [t, node] = pq.top();
            pq.pop();

            if (visited[node]) continue;
            
            visited[node] = 1;
            res = t;

            for (auto nxt : neighbors[node]) {
                auto [w, v] = nxt;
                if (visited[v] == 0) {
                    pq.push({w+t, v});
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) return -1;
        }
        return res;
    }
};
