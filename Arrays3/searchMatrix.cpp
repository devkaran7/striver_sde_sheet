bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int row = 0; row < n; row++){
            int firstElement = matrix[row][0];
            int lastElement = matrix[row][m-1];
            if(target <= lastElement && target >= firstElement){
                return binary_search(matrix[row].begin(), matrix[row].end(), target);
            }
        }
        return false;
    }
