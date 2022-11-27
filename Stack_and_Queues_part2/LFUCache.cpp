class Node{
public:
    int key;
    int val;
    int freq;
    Node* next;
    Node* prev;
    Node(int a, int b){
        key = a;
        val = b;
        freq = 1;
    }
};

class DLL{
public:
    Node* head;
    Node* tail;
    int size;
    DLL(){
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void deleteNode(Node* node){
        Node* prevNode = node->prev;
        prevNode->next = node->next;
        node->next->prev = prevNode;
        size--;
    }
    void insertAtHead(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next = node;
        node->next->prev = node;
        size++;
    }
};

class LFUCache {
public:
    unordered_map<int, DLL*> mp1;
    unordered_map<int, Node*> mp2;
    int freq;
    int cap;
    LFUCache(int capacity) {
        freq = 1;
        cap = capacity;
    }
    
    int get(int key) {
        if(mp2.find(key) == mp2.end()){
            return -1;
        }
        Node* node = mp2[key];
        mp1[node->freq]->deleteNode(node);
        node->freq = node->freq + 1;
        if(mp1[node->freq] == NULL){
            mp1[node->freq] = new DLL();
        }
        mp1[node->freq]->insertAtHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(cap == 0){
            return;
        }
        if(mp2.find(key) != mp2.end()){
            Node* node = mp2[key];
            node->val = value;
            mp1[node->freq]->deleteNode(node);
            node->freq = node->freq + 1;
            if(mp1[node->freq] == NULL){
                mp1[node->freq] = new DLL();
            }
            mp1[node->freq]->insertAtHead(node);
            return;
        }
        if(mp2.size() == cap){
            while(mp1[freq]->size == 0){
                freq++;
            }
            Node* lastNode = mp1[freq]->tail->prev;
            mp1[freq]->deleteNode(lastNode);
            mp2.erase(lastNode->key);
        }
        Node* newNode = new Node(key, value);
        if(mp1[newNode->freq] == NULL){
            mp1[newNode->freq] = new DLL();
        }
        mp1[newNode->freq]->insertAtHead(newNode);
        mp2[key] = newNode;
        freq = 1;
    }
};
