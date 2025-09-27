class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high) {
            int mid = (low + high) >> 1;
            if (nums[mid] == target) return mid;
            if (nums[mid] >= nums[low]) {
                // low to mid is sorted
                if (target <= nums[mid] && target >= nums[low]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                // mid to high is sorted
                if (target >= nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

/*

4, 5, 6, 7, 0, 1, 2

low -> 0 -> 4
high -> 6 -> 2
mid -> 3 -> 7
target = 0

low = 4 -> 0
high = 6 -> 2
mid = 5 -> 1
target = 0

low = 4
high = 4
mid = 4
target = 0

return 4

*/
