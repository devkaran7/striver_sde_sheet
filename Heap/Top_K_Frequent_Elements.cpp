vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto it : nums){
            mp[it]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto it : mp){
            if(pq.size() < k){
                pq.push({-it.second, it.first});
            }else if(it.second > -pq.top().first){
                pq.pop();
                pq.push({-it.second, it.first});
            }
        }
        vector<int> arr;
        while(pq.empty() == false){
            arr.push_back(pq.top().second);
            pq.pop();
        }
        return arr;
    }
