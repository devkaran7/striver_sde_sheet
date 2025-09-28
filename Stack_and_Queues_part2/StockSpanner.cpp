class StockSpanner {
private:
    // {value, index}
    stack<pair<int, int>> st;
    int index;
public:
    StockSpanner() {
        index = 0;
    }
    
    int next(int price) {
        while(!st.empty() && st.top().first <= price) {
            st.pop();
        }
        int prevGreaterIndex = (st.empty()) ? -1 : st.top().second;
        st.push(make_pair(price, index));
        int count = index - prevGreaterIndex;
        index++;
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

 /*
 
 100, 0, 80, 60, 70

 stack -> {100, 80, 70}

 100, 80, 60, 70, 70, 75, 85

 */
