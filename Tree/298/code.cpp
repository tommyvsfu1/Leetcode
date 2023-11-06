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
    int result = 0;
public:
    int longestConsecutive(TreeNode* root) {
        if (root == NULL) return 0;
        longest(root);
        return result;
    }
    int longest(TreeNode* root) {
        if (root == NULL) return 0;


        int leftSum = 0;
        int rightSum = 0;
        int res = 1;
        if (root->left != NULL) {
            leftSum = longest(root->left);
            if (root->val+1 == root->left->val) {
                res = max(res, leftSum + 1);
            }
        }
        if (root->right != NULL) {
            rightSum = longest(root->right);
            if (root->val+1 == root->right->val) {
                res = max(res, rightSum + 1);
            }
        }
        result = max(result, res);
        return res;
    }
};