class Solution {
public:
    inline int Dist(vector<int>& a, vector<int>& b) {
        return abs(a[0]-b[0]) + abs(a[1]-b[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>> graph(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    graph[i].push_back({Dist(points[i], points[j]), j});
                }
            }
        }


        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> visited(n, 0);

        pq.push({0, 0});
        int res = 0;
        while (!pq.empty()) {
            int w = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (visited[u]) continue;
            visited[u] = true;
            res += w;

            for (auto next : graph[u]) {
                if (visited[next.second]) continue;
                pq.push(next);
            }
        }
        return res;
    }
};
