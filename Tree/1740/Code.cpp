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
        if (root == NULL) {
            return {0,0};
        }

        pair<int,int> pl;
        pair<int,int> pr;
        pl = dfs(root->left, p, q);
        pr = dfs(root->right, p , q);

        int contain = pl.first + pr.first;
        int depth_count = max(pl.second, pr.second);
        if (pl.first > 0 || pr.first > 0) {
            depth_count++;
        }
        
        if (root->val == p || root->val == q) {
            contain++;
        }

        if (contain == 2 && res == NULL) {
            res = root;
            if (root->val == p) {
                res_dist = depth_count;
            }
            else if (root->val == q) {
                res_dist = depth_count;
            }
            else {
                res_dist = pl.second + 1 + pr.second + 1;
            }
        }
        return {contain, depth_count};
    }
    int findDistance(TreeNode* root, int p, int q) {
        dfs(root, p, q);
        return res_dist;
    }
};
