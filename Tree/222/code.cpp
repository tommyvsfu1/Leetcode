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
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        int h1 = findLeftDepth(root->left);
        int h2 = findRightDepth(root->left);
        int h3 = findLeftDepth(root->right);
        int h4 = findRightDepth(root->right);

        int res = 1;
        if (h1 == h2) {
            res += pow(2, h1) - 1;
            res += countNodes(root->right); 
        }
        else {
            res += pow(2, h3) - 1;
            res += countNodes(root->left);
        }
        return res;
    }
    int findLeftDepth(TreeNode* node) {
        int count = 0;
        while(node != NULL) {
            count++;
            node = node->left;
        }
        return count;
    }
    int findRightDepth(TreeNode* node) {
        int count = 0;
        while(node != NULL) {
            count++;
            node = node->right;
        }
        return count;
    }
};