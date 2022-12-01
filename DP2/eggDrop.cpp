class Solution
{
    private:
    int rec(int k, int e, vector<vector<int>> &dp){
        if(k == 0) return 0;
        if(e == 1) return k;
        if(dp[k][e] != -1) return dp[k][e];
        int ans = INT_MAX;
        for(int i = 1; i <= k; i++){
            ans = min(ans, 1 + max(rec(k-i, e, dp), rec(i-1, e-1, dp)));
        }
        return dp[k][e] = ans;
    }
    public:
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<int>> dp(k+1, vector<int>(n+1, -1));
        return rec(k, n, dp);
    }
};
