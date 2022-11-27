string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int m = INT_MAX;
        for(int i = 0; i < n; i++){
            m = min(m, (int)strs[i].size());
        }
        int i = 0;
        string result = "";
        bool flag = false;
        while(i < m && !flag){
            for(int j = 1; j < n; j++){
                if(strs[j][i] != strs[0][i]){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                result += strs[0][i];
            }
            i++;
        }
        return result;
    }
