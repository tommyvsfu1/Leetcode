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
    int res = 0;
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return false;
        DFS(root, targetSum);
        return res;
    }
    void DFS(TreeNode* node, int sum) {
        if (node->left == NULL && node->right == NULL) {
            if (sum == node->val) res = true;
            return;
        }
        if (node->left)
            DFS(node->left, sum-node->val);
        if (node->right)
            DFS(node->right, sum-node->val);
    }
};