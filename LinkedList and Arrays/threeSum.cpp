class Solution {
private:
    int increment(vector<int> &nums, int index){
        index++;
        while(index < nums.size() && nums[index] == nums[index-1]){
            index++;
        }
        return index;
    }
    int decrement(vector<int> &nums, int index){
        index--;
        while(index >= 0 && nums[index] == nums[index+1]){
            index--;
        }
        return index;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result;
        int i = 0;
        while(i < n){
            int start = i+1;
            int end = n-1;
            while(end > start){
                int sum = nums[i] + nums[start] + nums[end];
                if(sum == 0){
                    vector<int> temp = {nums[i], nums[start], nums[end]};
                    result.push_back(temp);
                    start = increment(nums, start);
                    end = decrement(nums, end);
                }else if(sum > 0){
                    end = decrement(nums, end);
                }else{
                    start = increment(nums, start);
                }
            }
            i = increment(nums, i);
        }
        return result;
    }
};
