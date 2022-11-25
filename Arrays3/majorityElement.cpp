int majorityElement(vector<int>& nums) {
        int element = -1;
        int countOfElement = 0;
        for(auto num : nums){
            if(num == element){
                countOfElement++;
            }else{
                countOfElement--;
                if(countOfElement <= 0){
                    element = num;
                    countOfElement = 1;
                }
            }
        }
        return element;
    }

// if it is given that answer may not exist, then you need to check if the element is majority element or not by running another for loop and counting occurances of element
