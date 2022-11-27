vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        deque<int> dq;
        vector<int> answer;
        for(int i = 0; i < k; i++){
            while(dq.empty() == false && arr[dq.front()] < arr[i]){
                dq.pop_front();
            }
            dq.push_front(i);
        }
        answer.push_back(arr[dq.back()]);
        for(int i = k; i < n; i++){
            int prev = i - k;
            while(dq.empty() == false && dq.back() <= prev){
                dq.pop_back();
            }
            while(dq.empty() == false && arr[dq.front()] < arr[i]){
                dq.pop_front();
            }
            dq.push_front(i);
            answer.push_back(arr[dq.back()]);
        }
        return answer;
    }
