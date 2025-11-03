/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        // code goes here.
        
        struct Node* p1 = head1;
        struct Node* p2 = head2;

        struct Node* prev = NULL;
        struct Node* curr = NULL;
        struct Node dummy(0);
        prev = &dummy;
        while (p1 && p2) {
            if (p1->data == p2->data) {
                curr = (struct Node *)malloc(sizeof(struct Node));
                curr->data = p1->data;
                curr->next = NULL;
                
                prev->next = curr;
                prev = curr;
                curr = curr->next;
                
                p1 = p1->next;
                p2 = p2->next;
            }
            else if (p1->data < p2->data) {
                p1 = p1->next;
            }
            else {
                p2 = p2->next;
            }
        }
        
        return dummy.next;
    }
};
