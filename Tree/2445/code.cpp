class Solution {
    int res = 0;
    unordered_map<int, int> mp;
public:
    int numberOfNodes(int n, vector<int>& queries) {
        for (auto q : queries)
            mp[q]++;
        dfs(1, 0, n);
        return res;
    }
    void dfs(int node, int flips, int n) {
        if (node > n) return;

        if (mp.find(node) != mp.end()) {
            flips += mp[node];
        }
        if (flips%2 == 1)
            res++;
        dfs(node*2, flips, n);
        dfs(node*2+1, flips, n);
    }
};