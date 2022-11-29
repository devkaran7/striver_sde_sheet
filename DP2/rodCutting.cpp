class Solution {
private:
    int rodCutting(int l, int r, vector<int> &cuts, int n, vector<vector<int>> &dp){
        if(r < l){
            return 0;
        }
        if(dp[l][r] != -1){
            return dp[l][r];
        }
        int prev = 0;
        if(l-1 >= 0){
            prev = cuts[l-1];
        }
        int next = n;
        if(r+1 < cuts.size()){
            next = cuts[r+1];
        }
        int cost = INT_MAX;
        for(int i = l; i <= r; i++){
            cost = min(cost, rodCutting(l, i-1, cuts, n, dp) + rodCutting(i+1, r, cuts, n, dp));
        }
        return dp[l][r] = cost + next - prev;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        sort(cuts.begin(), cuts.end());
        return rodCutting(0, m-1, cuts, n, dp);
    }
};
