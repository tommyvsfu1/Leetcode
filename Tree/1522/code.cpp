/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    int res = 0;
public:
    int diameter(Node* root) {
        LongestPathToLeaf(root);
        return res-1;
    }

    int LongestPathToLeaf(Node* node) {
        if (node == NULL) return 0;

        vector<int> hh;
        for (Node* child : node->children) {
            hh.push_back(LongestPathToLeaf(child));
        }

        sort(hh.rbegin(), hh.rend());

        if (hh.size() >= 2) {
            res = max(res, hh[0]+hh[1]+1);
            return hh[0] + 1;
        }
        else if (hh.size() >= 1) {
            res = max(res, hh[0] + 1);
            return hh[0] + 1;
        }
        else {
            res = max(res, 1);
            return 1;
        }
    }
};