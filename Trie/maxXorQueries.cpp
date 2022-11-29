struct Node{
    Node* links[2];
    
    bool containsKey(int x){
        return (links[x] != NULL);
    }
    
    Node* getNext(int x){
        return links[x];
    }
    
    void put(int x, Node* node){
        links[x] = node;
    }
};

class Trie{
private:
    Node* root;
    
public:
    Trie(){
        root = new Node();
    }
    
    void insert(int x){
        Node* node = root;
        for(int i = 29; i >= 0; i--){
            int bit = (x >> i) & 1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->getNext(bit);
        }
    }
    
    int getXor(int x){
        Node* node = root;
        int ans = 0;
        for(int i = 29; i >= 0; i--){
            int bit = (x >> i) & 1;
            if(node->containsKey(1 - bit)){
                ans += (1 << i);
                node = node->getNext(1 - bit);
            }else{
                node = node->getNext(bit);
            }
        }
        return ans;
    }
};

bool comp(vector<int> &v1, vector<int> &v2){
    if(v1[1] < v2[1]){
        return true;
    }
    return false;
}
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	//	Write your coode here.
    sort(arr.begin(), arr.end());
    int m = queries.size();
    vector<pair<int, pair<int, int>>> temp(m);
    for(int i = 0; i < m; i++){
        temp[i] = {queries[i][1], {queries[i][0], i}};
    }
    sort(temp.begin(), temp.end());
    int j = 0;
    int n = arr.size();
    Trie t;
    vector<int> ans(m, -1);
    for(int i = 0; i < m; i++){
        while(j < n && arr[j] <= temp[i].first){
            t.insert(arr[j]);
            j++;
        }
        if(j != 0){
            ans[temp[i].second.second] = t.getXor(temp[i].second.first);
        }
    }
    return ans;
}
