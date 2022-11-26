double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double, int>> density(n);
        for(int i = 0; i < n; i++){
            density[i] = {(arr[i].value * 1.0) / (arr[i].weight * 1.0) , i};
        }
        sort(density.begin(), density.end());
        int capacityLeft = W;
        double maxValue = 0;
        for(int i = n-1; i >= 0; i--){
            int index = density[i].second;
            if(arr[index].weight < capacityLeft){
                maxValue += arr[index].value;
                capacityLeft -= arr[index].weight;
            }else{
                maxValue += density[i].first * capacityLeft;
                break;
            }
        }
        return maxValue;
    }
