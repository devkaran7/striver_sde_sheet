class LRUCache {
public:
    class Node{
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int a, int b){
            key = a;
            val = b;
            next = NULL;
            prev = NULL;
        }
    };
    unordered_map<int, Node*> mp;
    int cap;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void deleteNode(Node* node){
        Node* prevNode = node->prev;
        prevNode->next = node->next;
        node->next->prev = prevNode;
    }
    
    void insertAtHead(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next = node;
        node->next->prev = node;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        Node* node = mp[key];
        deleteNode(mp[key]);
        insertAtHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            deleteNode(mp[key]);
            insertAtHead(node);
            node->val = value;
            return;
        }
        if(mp.size() == cap){
            //remove lru
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node* newNode = new Node(key, value);
        insertAtHead(newNode);
        mp[key] = newNode;
    }
};
