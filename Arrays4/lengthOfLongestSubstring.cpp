int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        int start = 0;
        int end = 0;
        int maxLen = 0;
        while(end < n){
            if(mp.find(s[end]) != mp.end()){
                start = max(start, mp[s[end]] + 1);
            }
            mp[s[end]] = end;
            end++;
            maxLen = max(maxLen, end - start);
        }
        return maxLen;
    }
