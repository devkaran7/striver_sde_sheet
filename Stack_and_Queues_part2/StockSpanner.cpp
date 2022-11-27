class StockSpanner {
private:
    stack<pair<int, int>> st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cnt = 1;
        while(st.empty() == false && st.top().first <= price){
            cnt += st.top().second;
            st.pop();
        }
        st.push({price, cnt});
        return cnt;
    }
};
