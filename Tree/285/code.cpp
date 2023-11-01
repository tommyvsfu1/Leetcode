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
    TreeNode* lastRead = NULL;
    TreeNode* res = NULL; 
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        DFS(root, p);
        return res;
    }
    void DFS(TreeNode* node, TreeNode* p) {
        if (node == NULL) return;

        DFS(node->left, p);
        
        if (lastRead == p && res == NULL) {
            res = node;
            return;
        }
        lastRead = node;
        DFS(node->right, p);
        
        return;
    }
};