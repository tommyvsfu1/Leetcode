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
    unordered_map<int,int> Map;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < inorder.size(); i++)
            Map[inorder[i]] = i;
        return dfs(preorder, inorder, 0, n-1, 0, n-1);
    }
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int i, int j, int a, int b) {
        if (i > j || a > b) return NULL; 

        TreeNode *new_node = new TreeNode(preorder[i]);

        int left_num = Map[preorder[i]] - a;
        int right_num = (b-a+1) - left_num - 1;

        new_node->left  = dfs(preorder, inorder, i+1, i+left_num, a, Map[preorder[i]]-1);
        new_node->right = dfs(preorder, inorder, i+left_num+1, j, Map[preorder[i]]+1, b);

        return new_node;
    }
};
