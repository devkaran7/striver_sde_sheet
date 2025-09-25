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

// if deadline <= 100 constraint not given
class Solution {
  public:
    vector<int> JobScheduling(vector<vector<int>>& Jobs) {
        priority_queue<pair<int,int>> byDeadline; // (deadline, profit)
        int maxD = 0;
        for (auto &j : Jobs) {
            byDeadline.push({j[1], j[2]});
            maxD = max(maxD, j[1]);
        }

        priority_queue<pair<int,int>> byProfit;   // (profit, deadline)
        long long total = 0; 
        int count = 0;

        for (int t = maxD; t >= 1; --t) {
            while (!byDeadline.empty() && byDeadline.top().first >= t) {
                auto [d, p] = byDeadline.top(); byDeadline.pop();
                byProfit.push({p, d});
            }
            if (!byProfit.empty()) {
                total += byProfit.top().first;
                byProfit.pop();
                ++count; // slot t used
            }
        }
        return {count, (int)total};
    }
};
