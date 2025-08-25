/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode *res;
    string res_source;
    string res_dest;
public:
    int dfs(TreeNode *root, int startValue, int destValue) {
        if (root == NULL) return 0;

        int count = 0;
        if (root->val == startValue || root->val == destValue) {
            count++;
        }
        
        count += (dfs(root->left, startValue, destValue) + dfs(root->right, startValue, destValue));
        if (count == 2 && res == NULL) {
            res = root;
        }
        return count;
    }
    void dfs_path_source(TreeNode *root, int source_value, string& s) {
        if (root == NULL) return;

        s += "U";
        dfs_path_source(root->left, source_value, s);
        s.pop_back();
        s += "U";
        dfs_path_source(root->right, source_value, s);
        s.pop_back();
        if (root->val == source_value) {
            res_source = s;
        }
    }
    void dfs_path_dest(TreeNode *root, int dest_value, string& s) {
        if (root == NULL) return;

        s += "L";
        dfs_path_dest(root->left, dest_value, s);
        s.pop_back();
        s += "R";
        dfs_path_dest(root->right, dest_value, s);
        s.pop_back();

        if (root->val == dest_value) {
            res_dest = s;
        }
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        res = NULL;
        res_source = "";
        res_dest = "";
        
        // Find LCA
        dfs(root, startValue, destValue);

        string s1 = "";
        string s2 = "";
        dfs_path_source(res, startValue, s1);
        dfs_path_dest(res, destValue, s2);

        return res_source + res_dest;
    }
};
