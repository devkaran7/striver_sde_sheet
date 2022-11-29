struct Node{
    Node* links[26];
    int cntEndwith = 0;
    int cntPrefix = 0;
    
    bool containsKey(char c){
        return (links[c - 'a'] != NULL);
    }
    
    Node* get(char c){
        return links[c-'a'];
    }
    
    void put(char c, Node* node){
        links[c-'a'] = node;
        
    }
    
    void increaseEnd(){
        cntEndwith++;
    }
    
    void increasePrefix(){
        cntPrefix++;
    }
    
    int getEnd(){
        return cntEndwith;
    }
    
    int getPrefix(){
        return cntPrefix;
    }
};
class Trie{
    private:Node* root;
    public:

    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }
    
    bool exist(string &s){
        Node* node = root;
        for(int i = 0; i < s.size(); i++){
            if(!node->containsKey(s[i])){
                return false;
            }
            node = node->get(s[i]);
            if(node->getEnd() == 0){
                return false;
            }
        }
        return true;
    }
};


string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie t;
    for(int i = 0; i < n; i++){
        string s = a[i];
        t.insert(s);
    }
    string maxi = "";
    for(int i = 0; i < n; i++){
        string s = a[i];
        if(t.exist(s)){
            if(maxi.length() < s.length()){
                maxi = s;
            }else if(maxi.length() == s.length()){
                maxi = min(maxi, s);
            }
        }
    }
    if(maxi.size() == 0){
        maxi = "None";
    }
    return maxi;
}
