class Node{
public:
    Node* links[2];
};
class Trie{
    Node* head;
public:
    Trie(){
        head = new Node();
    }
    void insert(int num){
        Node* node = head;
        for(int i = 30; i >= 0; i--){
            int bit = (num >> i) & 1;
            if(node->links[bit] == NULL){
                node->links[bit] = new Node();
            }
            node = node->links[bit];
        }
    }
    int getMaxXor(int num){
        Node* node = head;
        int maxi = 0;
        for(int i = 30; i >= 0; i--){
            int oppositeBit = (num >> i) & 1;
            int requiredBit = !oppositeBit;
            if(node->links[requiredBit] == NULL){
                node = node->links[oppositeBit];
            }else{
                node = node->links[requiredBit];
                maxi += (1 << i);
            }
        }
        return maxi;
    }
};
int maximumXor(vector<int> A)
{
    // Write your code here.   
    Trie t;
    for(auto x : A){
        t.insert(x);
    }
    int maxi = 0;
    for(auto x : A){
        maxi = max(maxi, t.getMaxXor(x));
    }
    return maxi;
}
