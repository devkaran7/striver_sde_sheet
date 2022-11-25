int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(auto num : nums){
            st.insert(num);
        }
        int maxLen = 0;
        for(auto num : nums){
            if(st.find(num) == st.end()) continue;
            int currLen = 1;
            int value = num-1;
            while(st.find(value) != st.end()){
                st.erase(value);
                currLen++;
                value--;
            }
            value = num+1;
            while(st.find(value) != st.end()){
                st.erase(value);
                currLen++;
                value++;
            }
            maxLen = max(maxLen, currLen);
        }
        return maxLen;
    }
