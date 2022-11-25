int majorityElement(vector<int>& nums) {
        int element = -1;
        int countOfElement = 0;
        for(auto num : nums){
            if(num == element){
                countOfElement++;
            }else if(countOfElement == 0){
                element = num;
                countOfElement = 1;
            }else{
                countOfElement--;
            }
        }
        return element;
    }

// if it is given that answer may not exist, then you need to check if the element is majority element or not by running another for loop and counting occurances of element
