void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool firstColZero = false;
        bool firstRowZero = false;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(matrix[row][col] == 0){
                    if(row == 0) firstRowZero = true;
                    if(col == 0) firstColZero = true;
                    matrix[row][0] = 0;
                    matrix[0][col] = 0;
                }
            }
        }
        for(int row = 1; row < n; row++){
            if(matrix[row][0] == 0){
                for(int col = 1; col < m; col++){
                    matrix[row][col] = 0;
                }
            }
        }
        for(int col = 1; col < m; col++){
            if(matrix[0][col] == 0){
                for(int row = 1; row < n; row++){
                    matrix[row][col] = 0;
                }
            }
        }
        if(firstColZero){
            for(int row = 0; row < n; row++){
                matrix[row][0] = 0;
            }
        }
        if(firstRowZero){
            for(int col = 0; col < m; col++){
                matrix[0][col] = 0;
            }
        }
    }
