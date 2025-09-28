class Solution {
public:
    int findCelebrity(int n) {
        int start = 0;
        int end = n-1;
        while(end > start) {
            if (knows(start, end)) {
                start++;
            } else {
                end--;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (i == start) continue;
            if (knows(start, i) || !knows(i, start)) return -1;
        }
        return start;
    }
};
