class Node{
public:
    Node* links[26];
};
class Trie{
    Node* head;
public:
    Trie(){
        head = new Node();
    }
private:
    int rec(Node* node){
        if(node == NULL){
            return 0;
        }
        int count = 1;
        for(int i = 0; i < 26; i++){
            count += rec(node->links[i]);
        }
        return count;
    }
public:
    void insert(string &s){
        int n = s.size();
        Node* node = head;
        for(int i = 0; i < n; i++){
            if(node->links[s[i] - 'a'] == NULL){
                node->links[s[i] - 'a'] = new Node();
            }
            node = node->links[s[i] - 'a'];
        }
    }
    
    int getDistinctSubstrings(){
        int count = 0;
        for(int i = 0; i < 26; i++){
            count += rec(head->links[i]);
        }
        return count;
    }
};
int distinctSubstring(string &word) {
    //  Write your code here.
    int n = word.size();
    string temp = "";
    Trie t;
    for(int i = n-1; i >= 0; i--){
        temp = word[i] + temp;
        t.insert(temp);
    }
    return t.getDistinctSubstrings();
}
