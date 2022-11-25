vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        vector<vector<int>> mergedIntervals;
        for(int i = 1; i < n; i++){
            int starti = intervals[i][0];
            int endi = intervals[i][1];
            if(starti > end){
                vector<int> newInterval = {start, end};
                mergedIntervals.push_back(newInterval);
                start = starti;
                end = endi;
            }else{
                end = max(end, endi);
            }
        }
        vector<int> newInterval = {start, end};
        mergedIntervals.push_back(newInterval);
        return mergedIntervals;
    }
