class Solution {
public:
    vector<vector<pair<long long,int>>> neighbors;
    vector<long long> minCost(int n, vector<vector<int>>& roads, vector<int>& appleCost, int k) {
        neighbors.resize(n);

        for (int i = 0; i < roads.size(); i++) {
            int a = roads[i][0] - 1;
            int b = roads[i][1] - 1;
            long long cost = roads[i][2];
            neighbors[a].push_back({cost*(k+1), b});
            neighbors[b].push_back({cost*(k+1), a});
        }
        
        vector<long long> res;
        for (int i = 0; i < n; i++) {
            long long r = getCost(i, n, appleCost, k);
            res.push_back(r);
            
        }

        return res;
    }
    long long getCost(int src, int n, vector<int>& appleCost, int k) {
        
        vector<pair<int,int>> visited(n, {0,0});
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

        pq.push({0, src});
        while(!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            if (visited[node].second == 1) continue;
 
            visited[node].first = cost;
            visited[node].second = 1;

            for (auto nxt : neighbors[node]) {
                auto [c, v] = nxt;
                if (visited[v].second == 0) {
                    pq.push({cost+c, v});
                }
            }
        }

        long long res = LLONG_MAX;
        for (int i = 0; i < visited.size(); i++) {
            if ( ((visited[i].first+appleCost[i]) < res) && visited[i].second == 1) {
                res = visited[i].first+appleCost[i];
            }
        }
        return res;
    }
};
