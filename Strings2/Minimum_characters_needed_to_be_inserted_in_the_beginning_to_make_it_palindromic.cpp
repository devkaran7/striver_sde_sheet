vector<int> longestPrefixSuffix(string &s){
    int n = s.size();
    int i = 1;
    int len = 0;
    vector<int> lps(n, 0);
    while(i < n){
        if(s[i] == s[len]){
            lps[i] = len + 1;
            i++;
            len++;
        }else{
            if(len != 0){
                len = lps[len-1];
            }else{
                i++;
            }
        }
    }
    return lps;
}

int Solution::solve(string s) {
    int n = s.size();
    vector<int> lps = longestPrefixSuffix(s);
    string t = s;
    reverse(t.begin(), t.end());
    int i = 0;
    int len = 0;
    vector<int> vec(n, 0);
    while(i < n){
        if(t[i] == s[len]){
            vec[i] = len + 1;
            len++;
            i++;
        }else{
            if(len == 0){
                i++;
            }else{
                len = lps[len-1];
            }
        }
    }
    return n-vec[n-1];
}
