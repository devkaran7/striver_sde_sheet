int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int leftMax = 0, rightMax = 0;
        int waterStored = 0;
        while(left < right){
            if(height[left] <= height[right]){
                if(height[left] <= leftMax){
                    waterStored += leftMax - height[left];
                }else{
                    leftMax = height[left];
                }
                left++;
            }else{
                if(height[right] <= rightMax){
                    waterStored += rightMax - height[right];
                }else{
                    rightMax = height[right];
                }
                right--;
            }
        }
        return waterStored;
    }
