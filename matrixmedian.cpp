int cnt(int x, vector<vector<int>> &matrix, int n, int m){
    int c = 0;
    for(int i = 0; i < n; i++){
        int low = 0;
        int high = m-1;
        while(high >= low){
            int mid = (low + high) >> 1;
            if(matrix[i][mid] >= x){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        c += low;
    }
    return c;
}

int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 1e9;
    int high = -1e9;
    for(int i = 0; i < n; i++){
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][m-1]);
    }
    while(high >= low){
        int mid = (high + low) >> 1;
        if(cnt(mid, matrix, n, m) <= (m*n)/2){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return high;
}
