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
    TreeNode* correctBinaryTree(TreeNode* root) {
        if (root == NULL) return root;

        unordered_set<int> Set;
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({root, NULL});
        Set.insert(root->val);
        while(!q.empty()) {
            int len = q.size();
            while(len--) {
                TreeNode* node = q.front().first;
                TreeNode* node_parent = q.front().second;
                q.pop();

                if (node->right && Set.find(node->right->val) != Set.end()) {
                    if (node_parent->left == node) {
                        node_parent->left = NULL;
                    }
                    else {
                        node_parent->right = NULL;
                    }
                    return root;
                }

                if (node->left) {
                    q.push({node->left, node});
                    Set.insert(node->left->val);
                }
                if (node->right) {
                    q.push({node->right, node});
                    Set.insert(node->right->val);
                }
            }
        }
        return root;

    }
};