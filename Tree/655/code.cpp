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
    int height;
public:
    vector<vector<string>> printTree(TreeNode* root) {
        height = getHeight(root);
        int width = pow(2, height) - 1;
        vector<vector<string>> res(height, vector<string>(width));
        
        int r = 0;
        int c = (width-1)/2;
        DFS(root, r, c, res);
        return res;
    }
    void DFS(TreeNode* node, int r, int c, vector<vector<string>>& res) {
        if (node == NULL) return;

        res[r][c] = to_string(node->val);
        
        DFS(node->left, r+1, c-pow(2,height-1-r-1), res);
        DFS(node->right, r+1, c+pow(2,height-1-r-1), res);

    }
    int getHeight(TreeNode* node) {
        if (node == NULL) return 0;      
        return max(getHeight(node->left), getHeight(node->right)) + 1;
    }
};