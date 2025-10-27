/*
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
*/
struct Node* insertAtPos(struct Node* head, int p, int x) {
    // Code here
    struct Node dummy;
    dummy.data = 0;
    dummy.prev = NULL;
    dummy.next = head;
    
    // if (head != NULL)
    //     head->prev = &dummy;
    
    struct Node *prev = NULL;
    struct Node *curr = &dummy;
    for (int i = 0; (i <= p+1) && (curr != NULL); i++) {
        prev = curr;
        curr = curr->next;
    }
    
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    
    if (prev) {
        prev->next = newNode;
        newNode->prev = prev;
        newNode->next = curr;
        if (curr) {
            curr->prev = newNode;
        }
    }
    
    // if (dummy.next != NULL)
    //     dummy.next->prev = NULL;
        
    return dummy.next;
}
