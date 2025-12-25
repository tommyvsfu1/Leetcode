class Solution {
public:
    vector<int> visited;
    vector<vector<int>> graph;
    vector<int> numNode;
    vector<int> res;
    int n;
    int total_dist;
    int count(int node) {
        if (visited[node] == true) return 0;

        int total_sum = 1;
        visited[node] = true;
        for (auto &nxt : graph[node]) {
            int num_node = count(nxt);
            numNode[nxt] = num_node;
            total_sum += num_node;
        } 
        return total_sum;
    }
    void dfs_dist(int node, int d) {
        if (visited[node]) {
            total_dist += (d-1);
            return;
        }

        visited[node] = true;
        for (auto &nxt : graph[node]) {
            dfs_dist(nxt, d+1);
        }
    }
    void dfs(int node, int d) {
        if (visited[node]) return;

        visited[node] = true;
        for (auto &nxt : graph[node]) {
            if (visited[nxt] == false) {
                int subNum = numNode[nxt] - 1;
                int upNum = n - 1 - subNum;
                res[nxt] = d - subNum + upNum - 1;
                dfs(nxt, res[nxt]);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        visited.resize(n, 0);
        graph.resize(n);
        numNode.resize(n);

        for (auto &e : edges) {
            graph[e[1]].push_back(e[0]);
            graph[e[0]].push_back(e[1]);
        }

        numNode[0] = count(0);
        for (int i = 0; i < n; i++) visited[i] = false;

        dfs_dist(0, 0);

        res.resize(n, 0);
        for (int i = 0; i < n; i++) visited[i] = false;
        res[0] = total_dist;
        this->n = n;
        dfs(0, res[0]);
        return res;
    }
};