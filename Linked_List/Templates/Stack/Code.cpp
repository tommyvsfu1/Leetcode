// Node structure
/* typedef struct Node {
    int data;
    struct Node* next;
} Node; */

// Function to create a new node
/* Node* createNode(int new_data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = new_data;
    node->next = NULL;
    return node;
} */

// Stack structure
typedef struct {
    // Initialize your data members
    Node *head; // top
    int  size;
} myStack;

// Initialize stack
void initStack(myStack* s) {
    s->head = NULL;
    s->size = 0;
}

bool isEmpty(myStack* s) {
    // Check if stack is empty
    return s->size == 0;
}

void push(myStack* s, int x) {
    // Adds an element to the top of the stack
    if (s != NULL) {
        Node *new_Node = createNode(x);
        
        Node dummy;
        dummy.next = s->head;
        
        Node *nxt = s->head;
        dummy.next = new_Node;
        new_Node->next = nxt;
        s->head = new_Node;
        s->size++;
    }
}

void pop(myStack* s) {
    // Removes an element from the top of the stack
    if (s != NULL) {
        Node dummy;
        dummy.next = s->head;
        
        Node *nxt = (s->head != NULL) ? s->head->next : NULL;
        if (s->head) free(s->head);
            
        dummy.next = nxt;
        s->head = nxt;
        s->size--;
    }
}

int peek(myStack* s) {
    // Returns the top element of the stack
    // If the stack is empty, return -1
    if (s != NULL && s->head != NULL) {
        return s->head->data;
    }
    else
        return -1;
}

int size(myStack* s) {
    // Returns the current size of the stack
    if (s != NULL) return s->size;
    return -1;
}
