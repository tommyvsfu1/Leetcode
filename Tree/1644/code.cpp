/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* res = NULL;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return res;        
    }
    int dfs(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (node == NULL) return 0;

        int left = dfs(node->left, p, q);
        int right = dfs(node->right, p, q);
        int self = ((node == p) || (node == q));
        int total = left + right + self;
        if (total == 2 && res == NULL)
            res = node;
        return total;

    }
};