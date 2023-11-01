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
    unordered_map<long long, int> mp;
    int res = 0;
public:
    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;
        DFS(root, 0, targetSum);
        return res;
    }
    void DFS(TreeNode* node, long long currSum, int target) {
        if (node == NULL) return;
        currSum += node->val;

        res += mp[currSum - target];

        mp[currSum]+=1;
        DFS(node->left, currSum, target);
        DFS(node->right, currSum, target);
        mp[currSum]-=1;
    }
};