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
    unordered_set<TreeNode*> s;
    TreeNode* res = NULL;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        for (auto node : nodes)
            s.insert(node);

        dfs(root);
        return res;
    }
    int dfs(TreeNode* node) {
        if (node == NULL) return 0;

        int left = dfs(node->left);
        int right = dfs(node->right);
        int self = (s.find(node) != s.end());
        if (left + right + self == s.size() && res == NULL) {
            res = node;
        }
        return left + right + self;

    }
};