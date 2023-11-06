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
    int longestConsecutive(TreeNode* root) {
        if (root == NULL) return 0;
        longest(root, root->val-1); // root->val-1是要強迫讓root進入此function能夠成立
        return res;
    }
    int longest(TreeNode* root, int upper_value) {
        if (root == NULL) return 0;

        int leftSum = longest(root->left, root->val);
        int rightSum = longest(root->right, root->val);

        res = max(res, max(leftSum, rightSum) + 1);

        if (root->val == upper_value + 1) {
            return max(leftSum, rightSum) + 1;
        }
        else {
            return 0;
        }
    }
};