vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> arr(n, -1);
        stack<int> st;
        unordered_map<int, int> mp;
        for(int i = n-1; i >= 0; i--){
            mp[nums2[i]] = i;
            while(st.empty() == false && nums2[st.top()] < nums2[i]){
                st.pop();
            }
            if(st.empty() == false){
                arr[i] = st.top();
            }
            st.push(i);
        }
        vector<int> ans;
        for(auto it : nums1){
            if(arr[mp[it]] != -1){
                ans.push_back(nums2[arr[mp[it]]]);
            }else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
