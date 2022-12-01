int findDuplicate(vector<int>& nums) {
    int slow = 0;
    int fast = 0;
    while(true){
        slow = nums[slow];
        fast = nums[nums[fast]];
        if(slow == fast) break;
    }
    fast = 0;
    while(slow != fast){
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

//a + x = k*c where a = distance of starting of loop from the start and x = distance of node meeting in loop from starting of loop. a = k*c - x
