long long merge(long long low,long long mid, long long high, long long arr[], long long n){
    long long i = low;
    long long j = mid+1;
    long long temp[n];
    long long start = low;
    long long cnt = 0;
    while(i <= mid && j <= high){
        if(arr[i] <= arr[j]){
            temp[start++] = arr[i++];
        }else{
            temp[start++] = arr[j++];
            cnt += mid - i + 1;
        }
    }
    while(i <= mid){
        temp[start++] = arr[i++];
    }
    while(j <= high){
        temp[start++] = arr[j++];
    }
    for(int a = low; a <= high; a++){
        arr[a] = temp[a];
    }
    return cnt;
}

long long mergeSort(long long low, long long high, long long arr[], long long n){
    if(low == high){
        return 0;
    }
    long long mid = (high + low) >> 1;
    long long leftResult = mergeSort(low, mid, arr, n);
    long long rightResult = mergeSort(mid + 1, high, arr, n);
    long long combinedResult = merge(low, mid, high, arr, n);
    return leftResult + rightResult + combinedResult;
}
long long getInversions(long long *arr, int n){
    return mergeSort(0, n-1, arr, n);
}
