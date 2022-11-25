void sortColors(vector<int>& nums) {
        int n = nums.size();
        int lastZero = 0;
        int firstTwo = n-1;
        int currentIndex = 0;
        while(currentIndex <= firstTwo){
            if(nums[currentIndex] == 0){
                swap(nums[lastZero], nums[currentIndex]);
                lastZero++;
                currentIndex++;
            }else if(nums[currentIndex] == 1){
                currentIndex++;
            }else{
                swap(nums[currentIndex], nums[firstTwo]);
                firstTwo--;
            }
        }
    }
