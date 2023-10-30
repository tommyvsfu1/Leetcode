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
    int longestUnivaluePath(TreeNode* root) {
        if (root == NULL) return 0;
        Univalue(root, root->val);
        return res-1;
    }
    int Univalue(TreeNode* node, int value) {
        if (node == NULL) return 0;

        int leftNum = Univalue(node->left, node->val);
        int rightNum = Univalue(node->right, node->val);

        res = max(res, 1+leftNum+rightNum);

        if (node->val == value) {
            return max(leftNum, rightNum) + 1;
        }
        else {
            return 0;
        }
    }
};