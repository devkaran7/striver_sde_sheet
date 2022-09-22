int getnum(char c){
        if(c == '(' || c== ')'){
            return 0;
        }
        if(c == '{' || c == '}'){
            return 1;
        }
        return 2;
    }

bool isValid(string s) {
        int n = s.size();
        stack<int> st;
        for(int i = 0; i < n; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(getnum(s[i]));
            }else{
                if(st.empty()){
                    return false;
                }
                if(st.top() == getnum(s[i])){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        return st.size() == 0;
    }
