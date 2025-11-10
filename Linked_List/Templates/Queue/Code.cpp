// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure
typedef struct {
    Node* front;
    Node* rear;
    int currSize;
} myQueue;

// Function to create a new node
Node* createNode(int new_data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = new_data;
    node->next = NULL;
    return node;
}

// Initialize queue
void initQueue(myQueue* q) {
    q->front = q->rear = NULL;
    q->currSize = 0;
}

bool isEmpty(myQueue* q) {
    // Check if queue is empty
    return q->currSize == 0;
}

void enqueue(myQueue* q, int x) {
    // Enqueue operation
    Node *new_Node = (Node *)malloc(sizeof(Node));
    new_Node->data = x;
    new_Node->next = NULL;
    
    if (q->rear) {
        q->rear->next = new_Node;
        q->rear = new_Node;
    }
    else {
        q->rear = new_Node;
        q->front = new_Node;
    }

    q->currSize++;
}

void dequeue(myQueue* q) {
    // Dequeue operation
    if (!isEmpty(q)) {
        Node *nxt = q->front->next;
        free(q->front);
        q->currSize--;
        
        if (isEmpty(q)) {
            q->front = NULL;
            q->rear = NULL;
        }
        else {
            q->front = nxt;
        }
    }
}

int getFront(myQueue* q) {
    // Get front element
    if (q->front)
        return q->front->data;
    else
        return -1;
}

int size(myQueue* q) {
    return q->currSize;
}
