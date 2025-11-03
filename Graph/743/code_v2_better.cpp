class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n);

        for (auto& t : times) {
            graph[t[0]-1].push_back({t[1]-1, t[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        pq.push({0, k-1});
        vector<int> dist(n, INT_MAX);
        dist[k-1] = 0;
        int res = 0;
        while(!pq.empty()) {
            auto [t, node] = pq.top();
            pq.pop();
            
            if (t > dist[node]) continue;

            res = t;

            for (auto [nei,w] : graph[node]) {
                if (dist[nei] > t+w) {
                    dist[nei] = t+w;
                    pq.push({t+w,nei});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (dist[i] == INT_MAX) return -1;
        }
        return res;
    }
};
