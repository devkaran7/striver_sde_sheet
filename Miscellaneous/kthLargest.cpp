class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto num : nums){
            if(pq.size() < k){
                pq.push(num);
            }else{
                if(pq.top() < num){
                    pq.pop();
                    pq.push(num);
                }
            }
        }
    }
    
    int add(int num) {
        if(pq.size() < k){
            pq.push(num);
        }else{
            if(pq.top() < num){
                pq.pop();
                pq.push(num);
            }
        }
        return pq.top();
    }
};
