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
    int res = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        LongestPathToLeaf(root);
        return res-1;
    }
    int LongestPathToLeaf(TreeNode* node) {
        if (node == NULL) return 0;

        int leftSum = LongestPathToLeaf(node->left);
        int rightSum = LongestPathToLeaf(node->right);

        res = max(res, leftSum + rightSum + 1);

        return max(leftSum, rightSum) + 1;
    }
};