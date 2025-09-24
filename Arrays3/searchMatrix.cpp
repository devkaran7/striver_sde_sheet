class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = n-1;
        while(low < high) {
            int mid = (low + high) >> 1;
            if (target > matrix[mid][m-1]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return binary_search(matrix[low].begin(), matrix[low].end(), target);
    }
};
