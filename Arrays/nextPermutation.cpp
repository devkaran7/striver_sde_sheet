class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                int justGreater = INT_MAX;
                int justGreaterIndex;
                for(int j = i + 1; j < n; j++){
                    if(nums[j] > nums[i] && nums[j] < justGreater){
                        justGreater = nums[j];
                        justGreaterIndex = j;
                    }
                }
                swap(nums[i], nums[justGreaterIndex]);
                sort(nums.begin() + i+1, nums.end());
                return;
            }
        }
        sort(nums.begin(), nums.end());
    }
};
