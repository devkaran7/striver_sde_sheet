class Solution {
  private:
    // min index with value > target
    int countLessThanEqualTo(vector<int> &vec, int target) {
        int low = 0;
        int high = vec.size() - 1;
        while(low <= high) {
            int mid = (low + high) >> 1;
            if (vec[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    int countLessThanEqualTo(vector<vector<int>> &mat, int target) {
        int count = 0;
        for (auto &row : mat) {
            count += countLessThanEqualTo(row, target);
        }
        return count;
    }
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int low = INT_MAX;
        int high = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                low = min(low, mat[i][j]);
                high = max(high, mat[i][j]);
            }
        }
        while(high >= low) {
            int mid = (low + high) >> 1;
            int count = countLessThanEqualTo(mat, mid);
            if (count > (n*m)/2) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

/*

median -> [1, 2, 3]
median -> middle element
element at min index with condition count(<= arr[index]) > n/2

tc -> log(m*n) * n * log(m)
sc -> O(1)

*/
