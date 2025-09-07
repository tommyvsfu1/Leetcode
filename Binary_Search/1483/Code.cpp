class TreeAncestor {
    vector<vector<int>> p;
public:
    TreeAncestor(int n, vector<int>& parent) {
        vector<vector<int>> p(n, vector<int>(32, -1));

        for (int i = 0; i < parent.size(); i++)
            p[i][0] = parent[i];

        for (int j = 1; j < 32; j++) {
            for (int i = 0; i < parent.size(); i++) {
                if (p[i][j-1] != -1)
                    p[i][j] = p[p[i][j-1]][j-1];
            }
        }

        this->p = p;
    }
    
    int getKthAncestor(int node, int k) {
        for (int j = 0; j < 32; j++) {
            if ((k>>j) & 1) {
                node = p[node][j];
                if (node == -1) break;
            }
        }

        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
