class Solution {
  private:
    int pow(int base, int power) {
        if (base == 0) return 0;
        int answer = 1;
        while(power) {
            if (power % 2) {
                // odd case
                // need to check answer * base < INT_MAX
                // answer < INT_MAX/base
                if (answer > INT_MAX/base) {
                    return INT_MAX;
                }
                answer = answer * base;
                power--;
            } else {
                // even case
                if (base > INT_MAX/base) {
                    return INT_MAX;
                }
                base = base * base;
                power = power >> 1;
            }
        }
        return answer;
    }
  public:
    int nthRoot(int n, int m) {
        // Code here
        int low = 1;
        int high = m;
        while(high >= low) {
            int mid = (low + high) >> 1;
            int midpowern = pow(mid, n);
            if (midpowern == m) {
                return mid;
            } else if (midpowern > m) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
};
