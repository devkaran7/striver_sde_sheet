private:
        static bool comp(Job j1, Job j2){
            if(j1.profit > j2.profit){
                return true;
            }
            return false;
        }
    public:
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        int totalProfit = 0, jobsDone = 0;
        sort(arr, arr + n, comp);
        vector<int> days(101, 0);
        for(int i = 0; i < n; i++){
            int profit = arr[i].profit;
            int deadline = arr[i].dead;
            for(int j = deadline; j >= 1; j--){
                if(days[j] == 0){
                    days[j] = 1;
                    totalProfit += profit;
                    jobsDone++;
                    break;
                }
            }
        }
        vector<int> result = {jobsDone, totalProfit};
        return result;
    } 
