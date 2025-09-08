class Solution {
    int matrix[1005][1005];
    vector<int> next[1005];
public:
    vector<int> closestNode(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> ans;
        for (auto& e : edges) {
            int p1 = e[0], p2 = e[1];
            next[p2].push_back(p1);
            next[p1].push_back(p2);
        }
        for (int i = 0; i < 1005; i++) 
            for (int j = 0; j < 1005; j++)
                matrix[i][j] = -1;

        for (int i = 0; i < n; i++)
            dfs(i, i, 0);

        for (auto& q : query) {
            int start = q[0], end = q[1], node = q[2];
            int ret = INT_MAX;
            int ret_node;
            int cur = start;


            while (1) {
                int find_nxt;
                if (matrix[cur][node] < ret) {
                    ret = matrix[cur][node];
                    ret_node = cur;
                }
                for (auto& nxt : next[cur]) {
                    if (matrix[cur][end] == matrix[nxt][end] + 1) {
                        find_nxt = nxt;
                        break;
                    }
                }
                
                if (cur == end) break;

                cur = find_nxt;

            }

            ans.push_back(ret_node);
        }
        return ans;
    }
    void dfs(int start, int cur, int dist) {
        if (matrix[start][cur] == -1) {
           matrix[start][cur] = dist;
            for (auto& nxt : next[cur]) {
                dfs(start, nxt, dist + 1);
            }
        }
        //for (auto& nxt : next[cur]) {
        //    if (nxt != start && matrix[start][nxt] == 0) {
        //        matrix[start][nxt] = dist + 1;
        //        dfs(start, nxt, dist + 1);
        //    }
        //}
    }
};
