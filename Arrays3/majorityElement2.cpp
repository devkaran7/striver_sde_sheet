class Solution {
private:
    bool isMajorityElement(vector<int> &nums, int candidate){
        int count = 0;
        for(auto num : nums){
            if(num == candidate){
                count++;
            }
        }
        int n = nums.size();
        if(count > n/3){
            return true;
        }
        return false;
    }
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int element1 = INT_MAX;
        int element2 = INT_MAX;
        int count1 = 0, count2 = 0;
        for(auto num : nums){
            if(num == element1){
                count1++;
            }else if(num == element2){
                count2++;
            }else if(count1 == 0){
                element1 = num;
                count1 = 1;
            }else if(count2 == 0){
                element2 = num;
                count2 = 1;
            }else{
                count1--;
                count2--;
            }
        }
        // cout << element1 << " " << element2 << endl;
        vector<int> answer;
        if(isMajorityElement(nums, element1)){
            answer.push_back(element1);
        }
        if(isMajorityElement(nums, element2)){
            answer.push_back(element2);
        }
        return answer;
    }
};
