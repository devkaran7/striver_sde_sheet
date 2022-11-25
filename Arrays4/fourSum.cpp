vector<vector<int>> fourSum(vector<int>& nums, long long target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        if(n < 4) return result;
        int i = 0;
        while(i < n){
            int j = i+1;
            while(j < n){
                int start = j+1;
                int end = n-1;
                while(start < end){
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[start] + (long long)nums[end];
                    if(sum == target){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[start]);
                        temp.push_back(nums[end]);
                        result.push_back(temp);
                        start++;
                        while(start < end && nums[start] == nums[start-1]){
                            start++;
                        }
                        end--;
                        while(end > start && nums[end] == nums[end+1]){
                            end--;
                        }
                    }else if(sum > target){
                        end--;
                        while(end > start && nums[end] == nums[end+1]){
                            end--;
                        }
                    }else{
                        start++;
                        while(start < end && nums[start] == nums[start-1]){
                            start++;
                        }
                    }
                }
                j++;
                while(j < n && nums[j] == nums[j-1]){
                    j++;
                }
            }
            i++;
            while(i < n && nums[i] == nums[i-1]){
                i++;
            }
        }
        return result;
    }
