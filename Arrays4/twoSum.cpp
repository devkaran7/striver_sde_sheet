vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> answer;
        int index = 0;
        for(auto num : nums){
            int firstElement = num;
            int secondElement = target - num;
            if(mp.find(secondElement) != mp.end()){
                answer = {index, mp[secondElement]};
                break;
            }
            mp[num] = index;
            index++;
        }
        return answer;
    }
