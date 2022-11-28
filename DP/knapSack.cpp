int knapSack(int w, int wt[], int val[], int n) 
{ 
   // Your code here
   int dp[n+1][w+1];
   for(int i = 0; i <= w; i++){
       dp[n][i] = 0;
   }
   for(int i = 0; i <= n; i++){
       dp[i][0] = 0;
   }
   for(int i = n-1; i>= 0; i--){
       for(int j = 1; j <= w; j++){
           if(j >= wt[i]){
               dp[i][j] = max(dp[i+1][j], val[i] + dp[i+1][j-wt[i]]);
           }else{
               dp[i][j] = dp[i+1][j];
           }
       }
   }
   return dp[0][w];
}
