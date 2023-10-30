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
private:
    int res = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        MaxDownPath(root);
        return res;
    }
    int MaxDownPath(TreeNode* node) {
        if (node == NULL) return 0;

        int leftSum = MaxDownPath(node->left);
        int rightSum = MaxDownPath(node->right);

        int maxTurnSum = node->val;
        if (leftSum > 0)
            maxTurnSum += leftSum;
        if (rightSum > 0)
            maxTurnSum += rightSum;

        res = max(res, maxTurnSum);

        if (leftSum < 0 && rightSum < 0)
            return node->val;
        else {
            return max(leftSum, rightSum) + node->val;
        }
    }
};