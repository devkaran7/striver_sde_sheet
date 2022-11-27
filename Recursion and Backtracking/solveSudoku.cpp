class Solution {
private:
    bool is_safe(int i, int j, vector<vector<char>> &arr){
        int x = (i/3) * 3;
        int y = (j/3) * 3;
        for(int ind = 0; ind < 9; ind++){
            if(arr[i][ind] == arr[i][j] && ind != j){
                return false;
            }
            if(arr[ind][j] == arr[i][j] && ind != i){
                return false;
            }
            int a = x + ind/3;
            int b = y + ind%3;
            if(arr[a][b] == arr[i][j] && (a != i || b != j)){
                return false;
            }
        }
        return true;
    }
    bool rec(int i, int j, vector<vector<char>> &arr){
        if(i == 9){
            return true;
        }
        if(j == 9){
            return rec(i+1, 0, arr);
        }
        if(arr[i][j] != '.'){
            return rec(i, j+1, arr);
        }
        for(char c = '1'; c <= '9'; c++){
            arr[i][j] = c;
            if(is_safe(i, j, arr) && rec(i, j+1, arr)){
                return true;
            }
            arr[i][j] = '.';
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        cout << rec(0, 0, board);
    }
};
