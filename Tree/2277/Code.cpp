class Solution {
    int dist2node[1005];
    vector<int> next[1005];
    bool visited[1005];
    int ret;
    int ret_node;
public:
    vector<int> closestNode(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> ans;
        for (auto& e : edges) {
            int p1 = e[0], p2 = e[1];
            next[p2].push_back(p1);
            next[p1].push_back(p2);
        }


        for (auto& q : query) {
            int start = q[0], end = q[1], node = q[2];
            for (int k = 0; k < 1005; k++)
                dist2node[k] = -1;
            
            dfs(node, 0);

            ret = INT_MAX;
            for (int k = 0; k < 1005; k++)
                visited[k] = false;
            dfs_se(start, end);
            if (dist2node[start] < ret) {
                ret = dist2node[start];
                ret_node = start;
            }
            ans.push_back(ret_node);
        }
        return ans;
    }
    void dfs(int cur, int dist) {
        if (dist2node[cur] == -1) {
            dist2node[cur] = dist;
            for (auto& nxt : next[cur]) {
                dfs(nxt, dist+1);
            }
        }
    }
    bool dfs_se(int cur, int end) {
        if (visited[cur] == true) {
            return false;
        }
        visited[cur] = true;
        if (cur == end) {
            return true;
        }
        bool isInPath = false;
        for (auto& nxt : next[cur]) {
            bool res = dfs_se(nxt, end);
            if (res) {
                isInPath = true;
                if (dist2node[nxt] < ret) {
                    ret = dist2node[nxt];
                    ret_node = nxt;
                }
            }
        }
        return isInPath;
    }
};
