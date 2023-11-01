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
    long long res = 0;
public:
    int pathSum(TreeNode* root, int targetSum) {
        DFS(root, targetSum);
        return res;
    }
    void DFS(TreeNode* node, int sum) {
        if (node == NULL) return;
        DFS(node->left, sum);
        DFS(node->right, sum);
        res += numPathSum(node, sum);
    }
    int numPathSum(TreeNode* node, long long sum) {
        if (node == NULL) return 0;

        if (node->val == sum)
            return 1 + numPathSum(node->left, 0) + numPathSum(node->right, 0);
        else
            return numPathSum(node->left, sum-node->val) + numPathSum(node->right, sum-node->val);
    }

};