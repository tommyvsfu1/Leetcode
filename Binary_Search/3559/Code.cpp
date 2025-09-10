/*
Formulate a up 2D arrary with information of each node's ancestors, in power of 2
Then, using the idea of lca to find distance between two nodes for the edges
Finally, calculate the possibilities based on the distance for each edge.
*/
#define MAXN (100005)
#define LOGN (17)
class Solution {
    vector<pair<int,int>> adj[100005];
    int up[MAXN][LOGN + 1];
    long long depth[MAXN];
    long long distRoot[MAXN]; 
public:
    void dfs(int cur, int parent) {
        up[cur][0] = parent;
        for (auto&[v,w] : adj[cur]) {
            if (v == parent) continue;
            depth[v] = depth[cur] + 1;
            distRoot[v] = distRoot[cur] + w;
            dfs(v, cur);
        }
    }
    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];

        for (int k = 0; k < LOGN; k++) {
            if ((1 << k) & diff) u = up[u][k];
        }

        if (u == v) return u;

        for (int k = LOGN; k >= 0; k--) {
            if (up[u][k] != up[v][k]) {
                u = up[u][k];
                v = up[v][k];
            }
        }
        return up[u][0];
    }
    long long dist(int u, int v) {
        int c = lca(u, v);
        long long res = distRoot[u] + distRoot[v] - 2 * distRoot[c];
        return res;
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        for (auto&e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 1});
        }

        depth[1] = 0;
        distRoot[1] = 0;
        dfs(1, 1);

        for (int k = 1; k <= LOGN; k++) {
            for (int j = 1; j <= n; j++) {
                up[j][k] = up[up[j][k-1]][k-1]; 
            }
        }

        vector<long long> power(n+1);
        long long M = 1e9 + 7;
        power[0] = 1;
        for (int i = 1; i <= n; i++) {
            power[i] = (power[i-1] * 2) % M;
        }

        vector<int> rets;
        for (auto&q : queries) {
            int u = q[0], v = q[1];

            long long d = dist(u, v);

            if (d == 0) {
                rets.push_back(0);
            }
            else {
                rets.push_back(power[d-1]);
            }
        }
        return rets;
    }
};
