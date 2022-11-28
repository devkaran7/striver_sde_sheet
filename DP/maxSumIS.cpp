int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int dp[n+1];
        dp[n] = 0;
        int ans = INT_MIN;
        for(int i = n-1; i >= 0; i--){
            dp[i] = arr[i];
            int temp = INT_MIN;
            for(int j = i+1; j<n; j++){
                if(arr[j] > arr[i]){
                    temp = max(temp, dp[j]);
                }
            }
            if(temp != INT_MIN){
                dp[i] += temp;
            }
            ans = max(ans, dp[i]);
        }
        return ans;
	}
