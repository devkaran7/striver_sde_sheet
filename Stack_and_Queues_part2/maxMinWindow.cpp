vector<int> maxMinWindow(vector<int> arr, int n) {
    // Write your code here.
    vector<int> result;
    vector<int> nextSmaller(n, n);
    vector<int> prevSmaller(n, -1);
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(st.empty() == false && arr[st.top()] >= arr[i]){
            st.pop();
        }
        if(st.empty() == false){
            prevSmaller[i] = st.top();
        }
        st.push(i);
    }
    while(st.empty() == false){
        st.pop();
    }
    for(int i = n-1; i >= 0; i--){
        while(st.empty() == false && arr[st.top()] >= arr[i]){
            st.pop();
        }
        if(st.empty() == false){
            nextSmaller[i] = st.top();
        }
        st.push(i);
    }
    vector<int> temp(n+1, INT_MIN);
    for(int i = 0; i < n; i++){
        int windowSize = nextSmaller[i] - prevSmaller[i] - 1;
        temp[windowSize] = max(temp[windowSize], arr[i]);
    }
    for(int i = n-1; i >= 1; i--){
        temp[i] = max(temp[i], temp[i+1]);
    }
    for(int i = 1; i <= n; i++){
        result.push_back(temp[i]);
    }
    return result;
}
