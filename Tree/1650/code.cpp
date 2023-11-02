/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
    Node* res = NULL;
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {

        Node* root = NULL;
        Node* node = p;
        while(node != NULL) {
            if (node->parent == NULL) root = node;            
            node = node->parent;
        }
        dfs(root, p, q);
        return res;
    }
    int dfs(Node* node, Node* p, Node* q) {
        if (node == NULL) return 0;

        int left = dfs(node->left, p, q);
        int right = dfs(node->right, p, q);
        int self = ((node == p) || (node == q));
        int total = left + right + self;
        if (total == 2 && res == NULL)
            res = node;
        return total;

    }
};