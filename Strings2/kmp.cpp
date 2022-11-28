class Solution {
private:
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
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        vector<int> needle_lps = longestPrefixSuffix(needle);
        int i = 0;
        int len = 0;
        while(i < n){
            if(haystack[i] == needle[len]){
                i++;
                len++;
            }else{
                if(len != 0){
                    len = needle_lps[len-1];
                }else{
                    i++;
                }
            }
            if(len == m){
                return i-m;
            }
        }
        return -1;
    }
};
