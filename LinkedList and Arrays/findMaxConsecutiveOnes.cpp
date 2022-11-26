int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int maxLen = 0;
        while(i < n){
            int j = i + 1;
            while(j < n && nums[i] == nums[j]){
                j++;
            }
            if(nums[i] == 1){
                maxLen = max(maxLen, j - i);
            }
            i = j;
        }
        return maxLen;
    }
