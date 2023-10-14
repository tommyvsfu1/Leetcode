class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, -1);

        queue<pair<int,int>> q;

        for (int i = 0; i < n; i++) {
            if (visited[i] != -1) continue;
            
            q.push({i, 0});
            while (!q.empty()) {
                auto [node, group] = q.front();
                q.pop();
                for (auto nxt : graph[node]) {
                    if (visited[nxt] != -1) {
                        if (visited[nxt] == group)
                            return false;
                    }
                    else {
                        visited[nxt] = 1 - group;
                        q.push({nxt, 1-group});
                    }
                }
            }
        }
        return true;
    }
};