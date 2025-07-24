//using Linklist
class Node {
public:
    int key, val;
    Node* next;
    Node* prev;
    Node(int key, int val) {
        this->key = key;
        this->val = val;
        next = prev = NULL;
    }
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> mp;
    Node *head, *tail;// 2 dummy ptr to avoid unnecessary if-else cond
    // node->prev | node | node->next
    // pre and next node is obtain by ptr and we just need to make
    //link between node->prev and node->next
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    //simply add node no need to check cond due to dummy ptr.
    // [-1,-1]...........[-1,-1]
    void insertAfterHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
public:
    //initialize
    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;//not found key
        Node* node = mp[key];
        //remove key from list
        removeNode(node);
        //make it most recent by adding at front
        insertAfterHead(node);
        return node->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            //update value if found key
            node->val = value;
            //make it most recent by removing & then adding at front
            removeNode(node);
            insertAfterHead(node);
        } 
        //if key not found need to add 
        // step1 check for capacity - if full remove LRU then add
        else {
            if (mp.size() == capacity) {
                Node* lru = tail->prev;
                removeNode(lru);
                mp.erase(lru->key);
                delete lru;
            }
            //insert new key
            Node* newNode = new Node(key, value);
            insertAfterHead(newNode);
            mp[key] = newNode;
        }
    }

    ~LRUCache() {
        Node* cur = head;
        while (cur) {
            Node* next = cur->next;
            delete cur;
            cur = next;
        }
    }
};