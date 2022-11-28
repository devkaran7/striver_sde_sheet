int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int> dp(m+1, 0);
        vector<int> temp(m+1, 0);
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(text1[i] == text2[j]){
                    temp[j] = 1 + dp[j+1];
                }else{
                    temp[j] = max(dp[j], temp[j+1]);
                }
            }
            dp = temp;
        }
        return dp[0];
    }
