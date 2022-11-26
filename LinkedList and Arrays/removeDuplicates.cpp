int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int cnt = 0;
        int n = nums.size();
        while(i < n){
            int j = i + 1;
            while(j < n && nums[i] == nums[j]){
                j++;
            }
            nums[cnt] = nums[i];
            i = j;
            cnt++;
        }
        return cnt;
    }
