class Solution{
private:
    int recursion(int i, int n, string &s, int dp[], vector<vector<int>> &isPalin){
        if(i == n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int ans = INT_MAX;
        for(int j = i; j < n; j++){
            if(isPalin[i][j]){
                ans = min(ans, 1 + recursion(j+1, n, s, dp, isPalin));
            }
        }
        return dp[i] = ans;
    }
public:
    int palindromicPartition(string s)
    {
        // code here
        int n = s.size();
        int dp[n];
        for(int i = 0; i < n; i++){
            dp[i] = -1;
        }
        vector<vector<int>> isPalin(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            // odd length
            int l = i;
            int r = i;
            while(l >= 0 && r < n && s[l] == s[r]){
                isPalin[l][r] = 1;
                l--;
                r++;
            }
            l = i;
            r = i+1;
            while(l >= 0 && r < n && s[l] == s[r]){
                isPalin[l][r] = 1;
                l--;
                r++;
            }
        }
        return recursion(0, n, s, dp, isPalin)-1;
    }
};
