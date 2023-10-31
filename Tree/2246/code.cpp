class Solution {
    int n = 0;
    vector<vector<int>> children;
    int res = 0;
public:
    int longestPath(vector<int>& parent, string s) {
        n = parent.size();
        children.resize(n);
        for (int i = 1; i < n; i++)
            children[parent[i]].push_back(i);

        dfs(0, s, '*');

        return res;
    }

    int dfs(int node, string& s, char upper_char) {

        vector<int> sub;
        for (int child : children[node]) {
            sub.push_back(dfs(child, s, s[node]));
        }

        sort(sub.rbegin(), sub.rend());

        if (sub.size() == 0) {
            res = max(res, 1);
            if (upper_char == s[node]) return 0;
            else return 1;
        }
        else if (sub.size() == 1) {
            res = max(res, 1 + sub[0]);
            if (upper_char == s[node]) return 0;
            else return 1+sub[0];
        }
        else {
            res = max(res, 1 + sub[0] + sub[1]);
            if (upper_char == s[node]) return 0;
            else return 1+sub[0];
        }

    }
};