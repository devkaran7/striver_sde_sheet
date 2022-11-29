class Solution {
private:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    bool isValid(int i, int j, int n, int m, vector<vector<int>> &arr, int color){
        if(i < 0 || i >= n) return false;
        if(j < 0 || j >= m) return false;
        if(arr[i][j] != color) return false;
        return true;
    }
    void dfs(int i, int j, int n, int m, vector<vector<int>> &arr, int c, int color){
        arr[i][j] = c;
        for(int a = 0; a < 4; a++){
            int new_i = i + dx[a];
            int new_j = j + dy[a];
            if(isValid(new_i, new_j, n, m, arr, color)){
                dfs(new_i, new_j, n, m, arr, c, color);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> arr = image;
        int n = arr.size();
        int m = arr[0].size();
        int c = arr[sr][sc];
        if(color == c) return arr;
        dfs(sr, sc, n, m, arr, color, c);
        return arr;
    }
};
