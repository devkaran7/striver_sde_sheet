class MedianFinder {
private:
    priority_queue<int> beforeMedian; //maxpq
    priority_queue<int, vector<int>, greater<int>> afterMedian; //minpq
    int total;
public:
    MedianFinder() {
        total = 0;
    }
    
    void addNum(int num) {
        beforeMedian.push(num);
        if(beforeMedian.size() - afterMedian.size() > 1){
            afterMedian.push(beforeMedian.top());
            beforeMedian.pop();
        }
        if(afterMedian.size() != 0 && afterMedian.top() < beforeMedian.top()){
            int a = afterMedian.top();
            afterMedian.pop();
            int b = beforeMedian.top();
            beforeMedian.pop();
            beforeMedian.push(a);
            afterMedian.push(b);
        }
        total++;
    }
    
    double findMedian() {
        double ans = beforeMedian.top();
        if(total % 2 == 0){
            ans += afterMedian.top();
            ans = ans / (2.0);
        }
        return ans;
    }
};
