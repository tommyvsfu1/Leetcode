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
    struct cmp {
        bool operator()(pair<double,int>& a, pair<double,int>& b) {
            return a.first < b.first;
        }
    };
    priority_queue<pair<double,int>, vector<pair<double,int>>, cmp> pq;
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        
        dfs(root, target, k);

        vector<int> res;
        while (!pq.empty()) {
            auto [diff, node] = pq.top();
            pq.pop();
            res.push_back(node);
        }
        return res;
    }
    void dfs(TreeNode *curr, double target, int k) {
        if (curr == NULL) return;

        if (pq.size() >= k) {
            if (fabs(curr->val - target) < fabs(pq.top().first)) {
                pq.pop();
                pq.push({fabs(curr->val-target), curr->val});
            }
        }
        else {
            pq.push({fabs(curr->val-target), curr->val});
        }

        dfs(curr->left, target, k);
        dfs(curr->right, target, k);
        return;
    }
};
