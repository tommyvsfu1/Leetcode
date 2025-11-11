typedef struct Node Node;

struct Node {
    int val;
    Node *next;
};

typedef struct {
    Node *head;
    Node *tail;
    int maxSize;
    int size;
} MyCircularQueue;

int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj && obj->head)
        return obj->head->val;
    else
        return -1;
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj && obj->tail)
        return obj->tail->val;
    else
        return -1;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->size == 0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size == obj->maxSize;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    
    if (obj) {
        if (obj->head != NULL) {
            Node *curr = obj->head;
            int size = obj->size;
            while (size--) {
                Node *nxt = curr->next;
                Node *free_Node = curr;
                free(free_Node);
                curr = nxt;
            }
        }
        free(obj);
    }
}
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *q = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    q->head = NULL;
    q->tail = NULL;
    q->maxSize = k;
    q->size = 0;
    return q;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj) == false) {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->next = NULL;
        new_node->val = value;
        if (obj->size == 0) {
            obj->tail = new_node;
            obj->head = new_node;

            obj->tail->next = obj->head;
            obj->head->next = obj->tail;
        }
        else {
            obj->tail->next = new_node;
            obj->tail = obj->tail->next;
            obj->tail->next = obj->head;
        }
        obj->size++;
        return true;
    }
    else {
        return false;
    }
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) return false;

    if (obj->size == 1) {
        free(obj->head);
        obj->head = NULL;
        obj->tail = NULL;
        obj->size--;
    }
    else {
        Node *nxt = obj->head->next;
        free(obj->head);
        obj->head = nxt;
        obj->tail->next = obj->head;
        obj->size--;
    }

    if (obj->size == 0) {
        obj->head = NULL;
        obj->tail = NULL;
    }
    return true;
}



/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/
