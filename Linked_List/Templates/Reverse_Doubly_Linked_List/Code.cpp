/*
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};
*/
struct Node* reverse(struct Node* head) {
    // Code here
    struct Node *prev = NULL;
    struct Node *curr = head;
    
    while (curr) {
        prev = curr->prev;
        struct Node *next = curr->next;
        
        curr->next = prev;
        curr->prev = next;
        
        curr = next;
    }
    
    if (prev) {
        head = prev->prev;
    }
    return head;
}
