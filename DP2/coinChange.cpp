int coinChange(vector<int>& coins, int amt) {
        int n = coins.size();
        int dp[n+1][amt+1];
        for(int i = 0; i <= amt; i++){
            dp[n][i] = INT_MAX;
        }
        for(int i = 0; i <= n; i++){
            dp[i][0] = 0;
        }
        for(int i = n-1; i >= 0; i--){
            for(int j = 1; j <= amt; j++){
                dp[i][j] = dp[i+1][j];
                if(j >= coins[i] && dp[i][j-coins[i]] != INT_MAX){
                    dp[i][j] = min(dp[i][j], 1 + dp[i][j-coins[i]]);
                }
            }
        }
        return (dp[0][amt] == INT_MAX) ? -1 : dp[0][amt];
    }
