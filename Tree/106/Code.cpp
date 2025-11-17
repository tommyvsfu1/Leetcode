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
    unordered_map<int, int> Map;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++)
            Map[inorder[i]] = i;
        
        return dfs(inorder, postorder, 0, n-1, 0, n-1);
    }
    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder, int i, int j, int a, int b) {
        if (i > j || a > b) return NULL;

        TreeNode* new_node = new TreeNode(postorder[b]);

        int left_num = Map[postorder[b]] - i;
        int right_num = (j-i+1) - left_num - 1;
        //cout << "=====================\n";
        //cout << "left num:" << left_num << ", right num:" << right_num << endl;
        //cout << i << " " << j << " " << a << " " << b << endl;
        //cout << Map[postorder[b]]+1 << " " << j << " " << b-right_num << " " << b-1 << endl;
        //cout << i << " " << Map[postorder[b]]-1 << " " << a << " " << b-right_num-1 << endl;
        //cout << "=====================\n";
        new_node->right = dfs(inorder, postorder, Map[postorder[b]]+1, j, b-right_num, b-1);
        new_node->left = dfs(inorder, postorder, i, Map[postorder[b]]-1, a, b-right_num-1);

        return new_node;
    }
};
