class Solution {
    int parents[1001];
    void Union(int u, int v) {
        u = Find(u);
        v = Find(v);
        
        if (u < v) parents[v] = u;
        else parents[u] = v;
    }
    int Find(int x) {
        if (parents[x] == x) return x;
        return parents[x] = Find(parents[x]);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       for (auto &e : edges) {
           parents[e[0]] = e[0];
           parents[e[1]] = e[1];
       } 

       vector<int> res;
       for (auto &e : edges) {
           int a = e[0];
           int b = e[1];
           if (Find(a) != Find(b)) {
               Union(a,b);
           }
           else {
               res = e;
               break;
           }
       }
       return res;
    }
};