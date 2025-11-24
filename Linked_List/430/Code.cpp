/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        return dfs(head);   
    }
    Node* dfs(Node* head) {
        if (head == NULL) return NULL;
        
        Node *curr = head;
        Node *child = curr->child;
        Node *next = curr->next;
        
        if (curr->child) {
            Node* flatten_head = dfs(curr->child);
            curr->next = flatten_head;
            if (flatten_head) {
                flatten_head->prev = curr;
            }
            curr->child = NULL;
            while (curr->next != NULL) {
                curr = curr->next;
            }
        }

        curr->next = dfs(next);
        if (curr->next) {
            curr->next->prev = curr;
        }

        return head;
    }
};

//1.記得flatten要把child = NULL
//2.flatten完，移動curr只能走child產生的，如果提前走到原本的curr->next，可能會誤判斷亂接node
