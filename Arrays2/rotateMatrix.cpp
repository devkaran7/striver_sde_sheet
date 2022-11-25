void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(row <= col){
                    swap(matrix[row][col], matrix[col][row]);
                }
            }
        }
        for(int row = 0; row < n; row++){
            int colStart = 0;
            int colEnd = n-1;
            while(colEnd > colStart){
                swap(matrix[row][colStart], matrix[row][colEnd]);
                colStart++;
                colEnd--;
            }
        }
    }
