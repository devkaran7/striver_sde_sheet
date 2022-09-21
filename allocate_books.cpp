bool canAllocate(vector<int> &A, int B, int mid){
    int n = A.size();
    int s = 1;
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(A[i] > mid){
            return false;
        }
        if(sum + A[i] <= mid){
            sum += A[i];
        }else{
            sum = A[i];
            s++;
        }
    }
    if(s <= B){
        return true;
    }
    return false;
}


int Solution::books(vector<int> &A, int B) {
    int n = A.size();
    if(B > n){
        return -1;
    }
    int low = INT_MIN;
    int high = 0;
    for(int i = 0; i < n; i++){
        high = high + A[i];
        low = max(low, A[i]);
    }
    while(high >= low){
        int mid = low + (high - low)/2;
        if(canAllocate(A, B, mid)){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return low;
}
