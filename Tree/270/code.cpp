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
    double res_value = INT_MAX;
public:
    int closestValue(TreeNode* root, double target) {
        Search(root, target);
        return res;
    }
    void Search(TreeNode* node, double target) {
        if (node == NULL) return;
        if (res_value >= abs(node->val-target)) {
            if (res_value == abs(node->val-target)) 
                res = min(res, node->val);
            else
                res = node->val;
            res_value = abs(node->val-target);
        }
        if (node->val < target) {
            Search(node->right, target);
        }
        else {
            Search(node->left, target);
        }
    }
};