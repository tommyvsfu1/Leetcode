class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        
        vector<vector<int>> graph(n);
        vector<unordered_set<int>> preSet(n);
        vector<int> indegree(n, 0);

        for (auto &relation : relations) {
            graph[relation[0]-1].push_back(relation[1]-1);
            indegree[relation[1]-1]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
            preSet[i].insert(i);
        }

        if (q.empty()) return -1;

        int res = 0;
        vector<int> visited(n, 0);
        while (!q.empty()) {
            int len = q.size();

            while (len--) {
                int node = q.front();
                visited[node] = true;
                q.pop();
        
                for (auto &nei : graph[node]) {
                    indegree[nei]--;

                    if (indegree[nei] == 0)
                        q.push(nei);
                }
            }
            res++;
        }
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) return -1;
        }
        return res;
    }
};
