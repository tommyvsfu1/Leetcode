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
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        vector<Node*> a;
        vector<Node*> b;

        while(p != NULL) {
            a.push_back(p);
            p = p->parent;
        }
        while(q != NULL) {
            b.push_back(q);
            q = q->parent;
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int i = 0;
        Node* res = NULL;
        while(i < a.size() && i < b.size()) {
            if (a[i] == b[i]) res = a[i];
            i++;
        }
        return res;
    }
};