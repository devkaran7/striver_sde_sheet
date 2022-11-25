vector<vector<int>> generate(int numRows) {
        vector<int> prefix(1, 1);
        vector<vector<int>> pascalsTriangle;
        for(int row = 0; row < numRows; row++){
            vector<int> currentRow = prefix;
            int prevRow = row-1;
            if(prevRow >= 0){
                int prevRowSize = pascalsTriangle[prevRow].size();
                for(int col = 0; col < prevRowSize-1; col++){
                    currentRow.push_back(pascalsTriangle[prevRow][col] + pascalsTriangle[prevRow][col+1]);
                }
                currentRow.push_back(1);
            }
            pascalsTriangle.push_back(currentRow);
        }
        return pascalsTriangle;
    }
