class MinStack {
private:
    stack<pair<int, int>> st;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val, val});
        }else{
            int mini = st.top().second;
            mini = min(mini, val);
            st.push({val, mini});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
