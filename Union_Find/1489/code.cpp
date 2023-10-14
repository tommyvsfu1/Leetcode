class Solution {
private:
    int N;
    int parent[100];
    int rank[100];

    int Find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = Find(parent[x]);
    }
    void Union(int u, int v) {
        u = Find(u);
        v = Find(v);
        if (u == v) return;
        if (rank[u] < rank[v]) parent[u] = v;
        else if (rank[v] < rank[u]) parent[v] = u;
        else {
            parent[v] = u;
            rank[u]++;
        }
    }
    int kruskal(vector<vector<int>>& edges, int k) {
        for (int i = 0; i < N; i++) 
            parent[i] = i;
        for (int i = 0; i < N; i++)
            rank[i] = 0;

        int cost = 0;
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i][3] == k) continue;
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            if (Find(u) != Find(v)) {
                Union(u, v);
                cost += w;
            }
        }

        unordered_set<int> Set;
        for (int i = 0; i < N; i++)
            Set.insert(Find(i));
            
        if (Set.size() != 1)
            return INT_MAX;


        return cost;
    }
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        N = n;
        for (int i = 0; i < edges.size(); i++)
            edges[i].push_back(i);

        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });

        int minMST = kruskal(edges, -1);

        unordered_set<int> Set1;
        unordered_set<int> Set2;
        for (int i = 0; i < edges.size(); i++) {
            int original_index = edges[i][3];

            int MST = kruskal(edges, original_index);

            if (MST > minMST) {
                Set1.insert(original_index);
            }
        }

        for (int i = 0; i < edges.size(); i++) {
            auto edge = edges[i];

            int original_index = edges[i][3];

            if (Set1.find(original_index) != Set1.end()) continue;


            edges.insert(edges.begin(), edge);

            int MST = kruskal(edges, -1);

            if (MST == minMST) {
                Set2.insert(original_index);
            }

            edges.erase(edges.begin());
        }

        vector<int> res1(Set1.begin(), Set1.end());
        vector<int> res2(Set2.begin(), Set2.end());
        return {res1,res2};

    }
};