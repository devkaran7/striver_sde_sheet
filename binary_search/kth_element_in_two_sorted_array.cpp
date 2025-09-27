class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int n = a.size();
        int m = b.size();
        if (m < n) return kthElement(b, a, k);
        // n is smaller
        int low = max(0, k - m);
        int high = min(n, k);
        while(high >= low) {
            int mid1 = (low + high) >> 1;
            int mid2 = k - mid1;
            int l1 = (mid1 == 0) ? INT_MIN : a[mid1-1];
            int l2 = (mid2 == 0) ? INT_MIN : b[mid2-1];
            int r1 = (mid1 == n) ? INT_MAX : a[mid1];
            int r2 = (mid2 == m) ? INT_MAX : b[mid2];
            if (l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            } else if (l1 > r2) {
                high = mid1 - 1;
            } else {
                low = mid1 + 1;
            }
        }
        return -1;
    }
};
