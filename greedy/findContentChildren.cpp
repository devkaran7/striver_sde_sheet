class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        int count = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (j == m) return count;
            if (g[i] <= s[j]) {
                count++;
                j++;
            }
        }
        return count;
    }
};
