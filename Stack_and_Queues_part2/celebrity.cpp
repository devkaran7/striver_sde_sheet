int celebrity(vector<vector<int> >& matrix, int n) 
    {
        // code here 
        stack<int> st;
        for(int i = 0; i < n; i++){
            st.push(i);
        }
        while(st.size() > 1){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if(matrix[a][b] == 1){
                st.push(b);
            }else{
                st.push(a);
            }
        }
        int possible_ans = st.top();
        for(int i = 0; i < n; i++){
            if(i == possible_ans) continue;
            if(matrix[possible_ans][i] != 0) return -1;
        }
        for(int i = 0; i < n; i++){
            if(i == possible_ans) continue;
            if(matrix[i][possible_ans] != 1) return -1;
        }
        return possible_ans;
    }
