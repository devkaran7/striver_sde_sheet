vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> st;
    int n = A.size();
    vector<int> arr(n, -1);
    for(int i = 0; i < n; i++){
        while(st.empty() == false && A[st.top()] >= A[i]){
            st.pop();
        }
        if(st.empty() == false){
            arr[i] = A[st.top()];
        }
        st.push(i);
    }
    return arr;
}
