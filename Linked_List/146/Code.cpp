struct Node {
    struct Node* next;
    struct Node* prev;
    int val;
};

class LRUCache {
    unordered_map<int,struct Node*> mp;
    unordered_map<struct Node*, int> mp_key;
    struct Node *head;
    struct Node *tail;
    int capacity;
public:
    LRUCache(int capacity) {
        head = (struct Node*)malloc(sizeof(struct Node));
        tail = (struct Node*)malloc(sizeof(struct Node));

        head->next = tail;
        tail->prev = head;
        tail->next = NULL;
        head->prev = NULL;
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        update(key);
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key]->val = value;
            update(key);
        }
        else if (mp.size() >= capacity) {
            pop();
            push(key, value);
        } 
        else {
            push(key, value);
        }
    }
    void update(int key) {
        struct Node* node = mp[key];

        struct Node* prev = node->prev;
        struct Node* nxt = node->next;


        prev->next = nxt;
        nxt->prev = prev;

        tail->prev->next = node;
        node->prev = tail->prev;
        node->next = tail;
        tail->prev = node;

    }
    void push(int key, int value) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->val = value;
        new_node->next = NULL;        
        new_node->prev = NULL;

        mp[key] = new_node;
        mp_key[new_node] = key;
 
        tail->prev->next = new_node;
        new_node->prev = tail->prev;
        new_node->next = tail;
        tail->prev = new_node;
    }
    void pop() {

        int key = mp_key[head->next];
        mp_key.erase(head->next);
        mp.erase(key);

        struct Node* node = head->next;

        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
