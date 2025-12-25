class Solution {
    vector<vector<int>> graph;
    int group_cnt[22];
    vector<bool> visited;
    long long res;
public:
    vector<int> dfs(int u, vector<int>& group) {
        
        vector<int> curr(22, 0);

        if (visited[u] == true) return curr;

        visited[u] = true;

        curr[group[u]] += 1;

        for (auto &nxt : graph[u]) {
            if (visited[nxt] == true) continue;

            
            vector<int> left = dfs(nxt, group);

            for (int c = 1; c <= 20; c++) {
                int right = group_cnt[c] - left[c];

                res += (long)left[c] * (long)right;

                curr[c] += left[c];
            }
        }
        return curr;
    }
    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        
        graph.resize(n);
        visited.resize(n);
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        for (int i = 0 ; i < group.size(); i++) {
            group_cnt[group[i]]++;
        }

        dfs(0, group);

        return res;
    }
};