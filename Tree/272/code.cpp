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
    priority_queue<pair<double, int>> pq;
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;

        DFS(root, target, k);
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
    void DFS(TreeNode* node, double target, int k) {
        if (node == NULL) return;

        DFS(node->left, target, k);

        pq.push({abs(node->val - target), node->val});
        
        if (pq.size() > k) {
            pq.pop();
        }

        DFS(node->right, target, k);
        
        return;
    }
};