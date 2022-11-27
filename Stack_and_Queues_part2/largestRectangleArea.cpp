int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> prevSmaller(n, -1);
        vector<int> nextSmaller(n, n);
        for(int i = 0; i < n; i++){
            while(st.empty() == false && heights[st.top()] >= heights[i]){
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
            while(st.empty() == false && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty() == false){
                nextSmaller[i] = st.top();
            }
            st.push(i);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, heights[i] * (nextSmaller[i] - prevSmaller[i] - 1));
        }
        return ans;
    }
