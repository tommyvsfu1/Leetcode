class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;

        vector<int> indegree(n, 0);
        vector<vector<int>> graph(n, vector<int>());
        for (auto prep : prerequisites) {
            indegree[prep[1]]++;
            graph[prep[0]].push_back(prep[1]);
        }

        queue<int> q;
        vector<unordered_set<int>> preSet(n);

        for (int i = 0; i < n; i++) {
            preSet[i].insert(i);
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while(q.size() != 0) {
            int totalSize = q.size();
            for (int k = 0; k < totalSize; k++) {
                int node = q.front();
                for (auto nei : graph[node]) {
                    indegree[nei]--;

                    for (auto prep : preSet[node]) {
                        preSet[nei].insert(prep);
                    }

                    if (indegree[nei] == 0) {
                        q.push(nei);
                    }
                }
                q.pop();
            }
        }

        vector<bool> res;
        for (auto query : queries) {
            res.push_back(preSet[query[1]].find(query[0]) != preSet[query[1]].end());
        }
        return res;
    }
};