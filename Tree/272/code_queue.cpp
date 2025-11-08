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
    queue<int> q;
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        
        dfs(root, target, k);
        vector<int> res;
        while (q.size() > 0) {
            int node = q.front();
            q.pop();
            res.push_back(node);
        }
        return res;
    }
    void dfs(TreeNode *curr, double target, int k) {
        if (curr == NULL) return;

        dfs(curr->left, target, k);

        if (q.size() < k) {
            q.push(curr->val);
            dfs(curr->right, target, k);
        } 
        else {
            if (fabs(curr->val - target) < fabs(q.front() - target)) {
                q.pop();
                q.push(curr->val);
                dfs(curr->right, target, k);
            }
        }
        return;
    }
};
