class MyStack {
private:
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        int sz = q.size();
        for(int i = 0; i < sz - 1; i++){
            int num = q.front();
            q.pop();
            q.push(num);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ans = q.front();
        q.pop();
        return ans;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};
