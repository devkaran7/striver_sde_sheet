class Node{
public:
    Node* arr[26];
    bool flag;
    Node(){
        flag = false;
    }
};

class Trie {
    Node* head;
public:

    /** Initialize your data structure here. */
    Trie() {
        head = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = head;
        int n = word.size();
        for(int i = 0; i < n; i++){
            if(node->arr[word[i] - 'a'] == NULL){
                node->arr[word[i]-'a'] = new Node();
            }
            node = node->arr[word[i]-'a'];
        }
        node->flag = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node = head;
        int n = word.size();
        for(int i = 0; i < n; i++){
            if(node->arr[word[i] - 'a'] == NULL){
                return false;
            }
            node = node->arr[word[i]-'a'];
        }
        return node->flag;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        Node* node = head;
        int n = word.size();
        for(int i = 0; i < n; i++){
            if(node->arr[word[i] - 'a'] == NULL){
                return false;
            }
            node = node->arr[word[i]-'a'];
        }
        return true;
    }
};
