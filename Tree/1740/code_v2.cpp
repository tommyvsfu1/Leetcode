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
    TreeNode *res;
    int res_dist;
public:
    pair<int,int> dfs(TreeNode* root, int p, int q) {
        if (root == NULL) return {-1, -1};

 

        pair<int,int> p1 = dfs(root->left, p, q);
        pair<int,int> p2 = dfs(root->right,p, q);
        
        int a = -1;
        int b = -1;

        if (p1.first != -1) {
            a = p1.first + 1;
        }
        else if (p2.first != -1) {
            a = p2.first + 1;
        }
        else if (root->val == p) {
            a = 0;
        }

        if (p1.second != -1) {
            b = p1.second + 1;
        }
        else if (p2.second != -1) {
            b = p2.second + 1;
        }
        else if (root->val == q) {
            b = 0;
        }

        if (res_dist == -1 && a != -1 && b != -1) {
            res_dist = a + b;
        }     

        return {a,b};
    }
    int findDistance(TreeNode* root, int p, int q) {
        res_dist = -1;
        dfs(root, p, q);
        return res_dist;
    }
};
