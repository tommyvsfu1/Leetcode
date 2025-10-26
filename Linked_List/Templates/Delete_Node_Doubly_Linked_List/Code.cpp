/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    Node* delPos(Node* head, int x) {
        // code here
        struct Node dummy(0);
        dummy.next = head;
        dummy.prev = NULL;
        if (head != NULL) {
            head->prev= &dummy;
        }
        
        Node *curr = &dummy;
        int i = 0;
        while (i != x && curr != NULL) {
            curr = curr->next;
            i++;
        }
        
        if (curr) {
            Node *prev = curr->prev;
            Node *next = curr->next;
            if (prev) {
                prev->next = next;
            }
            if (next) {
                next->prev = prev;
            }
        }
        if (dummy.next != NULL) {
            dummy.next->prev = NULL;
        }
        return dummy.next;
    }
};
