int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, int>> meetings(n);
        for(int i = 0; i < n; i++){
            meetings[i] = {end[i], start[i]};
        }
        sort(meetings.begin(), meetings.end());
        int availableFrom = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(availableFrom <= meetings[i].second){
                cnt++;
                availableFrom = meetings[i].first + 1;
            }
        }
        return cnt;
    }
