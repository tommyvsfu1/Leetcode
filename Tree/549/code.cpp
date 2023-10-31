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
    unordered_map<TreeNode*, int> LD;
    unordered_map<TreeNode*, int> LI;
public:
    int longestConsecutive(TreeNode* root) {
        if (root == NULL) return 0;
        LongestIncreasing(root);
        LongestDecreasing(root);
        DFS(root);
        return res;
    }
    void DFS(TreeNode* node) {
        if (node == NULL) return;
        DFS(node->left);
        res = max(res, LD[node]+LI[node]-1);
        DFS(node->right);
    }
    int LongestIncreasing(TreeNode* node) {
        if (node == NULL) return 0;
        
        int Iright = LongestIncreasing(node->right);
        int Ileft = LongestIncreasing(node->left);

        int result = 1;
        if (node->right) {
            if (node->val+1 == node->right->val) {
                result = max(result, Iright+1);
            }
        }
        if (node->left) {
            if (node->val+1 == node->left->val) {
                result = max(result, Ileft+1);
            }
        }
        LI[node] = result;
        return result;
    }
    int LongestDecreasing(TreeNode* node) {
        if (node == NULL) return 0;

        int Dright = LongestDecreasing(node->right);
        int Dleft = LongestDecreasing(node->left);

        int result = 1;
        if (node->right) {
            if (node->val-1 == node->right->val) {
                result = max(result, Dright+1);
            }
        }
        if (node->left) {
            if (node->val-1 == node->left->val) {
                result = max(result, Dleft+1);
            }
        }
        LD[node] = result;
        return result;
  
    }
};
