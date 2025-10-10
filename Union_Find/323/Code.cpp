class Solution {
    int parents[2001];
    int rank[2001];
    bool Union(int a, int b) {
        int pa = Find(a);
        int pb = Find(b);

        if (pa == pb) return false;

        if (rank[pa] > rank[pb]) {
            parents[pb] = pa;
        }
        else if (rank[pb] > rank[pa]) {
            parents[pa] = pb;
        }
        else {
            parents[pa] = pb;
            rank[pb]++;
        }
        return true;
    }
    int Find(int u) {
        if (u != parents[u])
            parents[u] = Find(parents[u]);
        return parents[u];
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < n; i++)
            parents[i] = i;

        for (auto e : edges) {
            int a = e[0];
            int b = e[1];
            Union(a,b);
        }

        unordered_set<int> Set;
        for (int i = 0; i < n; i++) {
            Set.insert(Find(i));
        }
        return Set.size();
    }
};

