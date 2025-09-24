class Solution {
private:
    void swapInClockwiseDirection(int &a, int &b, int &c, int &d) {
        int temp = d;
        d = c;
        c = b;
        b = a;
        a = temp;
    }
private:
    void rotateIthLayer(int i, vector<vector<int>> &matrix) {
        int n = matrix.size();
        for (int j = i; j < n-i-1; j++) {
            swapInClockwiseDirection(matrix[i][j], matrix[j][n-i-1], matrix[n-i-1][n-j-1], matrix[n-j-1][i]);
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int i = 0;
        while (i < n - i - 1){
            rotateIthLayer(i, matrix);
            i++;
        }
    }
};
