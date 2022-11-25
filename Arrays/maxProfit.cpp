int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxValue = INT_MIN;
        int maxProfit = 0;
        for(int i = n-1; i >= 0; i--){
            maxValue = max(maxValue, prices[i]);
            //if i bought it on day i then what is the max profit i can generate
            maxProfit = max(maxProfit, maxValue - prices[i]);
        }
        return maxProfit;
    }
