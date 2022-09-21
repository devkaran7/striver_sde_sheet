bool check(int arr[], int n, int c, int mid){
    int cnt = 1;
    int prev = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] - prev > mid){
            cnt++;
            prev = arr[i];
        }
    }
    if(cnt >= c){
        return true;
    }
    return false;
}

void solve(){
    int n, c;
    cin >> n >> c;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int low = 0;
    int high = arr[n-1];
    while(high >= low){
        int mid = (high + low) >> 1;
        if(check(arr, n, c, mid)){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    cout << low << endl;
}
