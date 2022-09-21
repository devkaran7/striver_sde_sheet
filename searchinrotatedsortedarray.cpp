int search(vector<int>& arr, int x) {
        int low = 0;
        int high = arr.size() -1;
        while(high >= low){
            int mid = (high + low)/2;
            if(arr[mid] == x){
                return mid;
            }
            if(arr[low] <= arr[mid]){
                if(x <= arr[mid] && x >= arr[low]){
                    high = mid -1;
                }else{
                    low = mid + 1;
                }
            }else{
                if(x >= arr[mid] && x <= arr[high]){
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
