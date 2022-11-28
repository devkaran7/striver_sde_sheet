int matrixMultiplication(int n, int arr[])
    {
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = n-1; i >= 0; i--){
            for(int k = 0; k < n; k++){
                if(i+1 < k){
                    dp[i][k] = INT_MAX;
                    for(int j = i+1; j < k; j++){
                        dp[i][k] = min(dp[i][k], arr[i]*arr[k]*arr[j] + dp[i][j] + dp[j][k]);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
