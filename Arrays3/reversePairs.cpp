class Solution {
private:
    int merge(vector<int>& nums, int low ,int mid, int high){
        int count = 0;
        int left = low;
        int right = mid+1;
        while(left <= mid && right <= high){
            if((long)nums[left] > (long)nums[right]*2){
                count += mid-left+1;
                right++;
            }else{
                left++;
            }
        }
        vector<int> b;
        int l = low;
        int r = mid+1;
        while(l <= mid && r <= high){
            if(nums[l] <= nums[r]){
                b.push_back(nums[l++]);
            }else{
                b.push_back(nums[r++]);
            }
        }
        while(l <= mid){
            b.push_back(nums[l++]);
        }
        while(r <= high){
            b.push_back(nums[r++]);
        }
        for(int i = low; i <= high; i++){
            nums[i] = b[i-low];
        }
        return count;
    }
    int mergesort(vector<int>& nums, int low, int high){
        if(high == low){
            return 0;
        }
        int mid = (high + low) >> 1;
        int left = mergesort(nums, low, mid);
        int right = mergesort(nums, mid + 1, high);
        int cnt = merge(nums, low, mid, high);
        return cnt + left + right;
    }
    
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergesort(nums, 0, n-1);
    }
};
