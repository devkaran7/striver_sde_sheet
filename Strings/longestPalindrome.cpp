class Solution {
private:
    string getMaxPalin(int l, int r, string &s){
        int n = s.size();
        while(l >= 0 && r < n && s[l] == s[r]){
            l--;
            r++;
        }
        return s.substr(l+1, r-l-1);
    }
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen = 0;
        string str = "";
        for(int i = 0; i < n; i++){
            //odd length
            string oddLength = getMaxPalin(i, i, s);
            if(oddLength.size() > maxLen){
                maxLen = oddLength.size();
                str = oddLength;
            }
            //even length
            string evenLength = getMaxPalin(i, i+1, s);
            if(evenLength.size() > maxLen){
                maxLen = evenLength.size();
                str = evenLength;
            }
        }
        return str;
    }
};
