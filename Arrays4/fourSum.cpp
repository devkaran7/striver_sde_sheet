class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> quadruplets;
        int i = 0;
        while (i < n) {
            if (i != 0 && nums[i - 1] == nums[i]) {
                i++;
                continue;
            }
            int j = i + 1;
            while (j < n) {
                if (j != i + 1 && nums[j] == nums[j - 1]) {
                    j++;
                    continue;
                }
                int start = j + 1;
                int end = n - 1;
                long long targetSum = target;
                targetSum -= nums[i] + nums[j];
                while (start < end) {
                    if (start != j + 1 && nums[start] == nums[start - 1]) {
                        start++;
                        continue;
                    }
                    if (end != n - 1 && nums[end] == nums[end + 1]) {
                        end--;
                        continue;
                    }
                    long long sum = nums[start] + nums[end];
                    if (sum == targetSum) {
                        quadruplets.push_back(
                            {nums[i], nums[j], nums[start], nums[end]});
                        start++;
                    } else if (sum < targetSum) {
                        start++;
                    } else {
                        end--;
                    }
                }
                j++;
            }
            i++;
        }
        return quadruplets;
    }
};
