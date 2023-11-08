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
public:
    void flatten(TreeNode* root) {
        traversal(root);
    }
    TreeNode* traversal(TreeNode* node) {
        if (node == NULL) return node;

        TreeNode* left = NULL;
        TreeNode* right = NULL;
        
        left = traversal(node->left);
        right = traversal(node->right);

        node->left = NULL;
        if (left != NULL) {
            node->right = left;
            TreeNode* tail = left;
            while(tail->right) {
                tail = tail->right;
            }
            tail->right = right;
        }
        else {
            node->right = right;
        }
        return node;
    }
};