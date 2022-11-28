int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int maxi = 1;
    int mini = 1;
    int prod = INT_MIN;
    for(int i = 0; i < n; i++){
        int temp = maxi;
        maxi = max(nums[i], max(nums[i]*maxi, nums[i]*mini));
        mini = min(nums[i], min(nums[i]*temp, nums[i]*mini));
        prod = max(prod, maxi);
        if(nums[i] == 0){
            maxi = 1;
            mini = 1;
        }
    }
    return prod;
}
