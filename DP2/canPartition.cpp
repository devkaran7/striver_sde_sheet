bool canPartition(vector<int>& nums) {
  int sum = 0;
  int n = nums.size();
  for(int i = 0; i < n; i++){
      sum += nums[i];
  }
  if(sum % 2 == 1){
      return false;
  }
  int dp[n+1][sum/2 + 1];
  for(int i = 0; i <= sum/2; i++){
      dp[n][i] = 0;
  }
  for(int i = 0; i < n; i++){
      dp[i][0] = 1;
  }
  for(int i = n-1; i>= 0; i--){
      for(int j = 1; j <= sum/2; j++){
          dp[i][j] = dp[i+1][j];
          if(j >= nums[i]){
              dp[i][j] = max(dp[i][j], dp[i+1][j-nums[i]]);
          }
      }
  }
  return dp[0][sum/2];
}
