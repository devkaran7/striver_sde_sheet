class Solution{
    private:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    string dir = "DURL";
    vector<string> allPaths;
    bool is_safe(int i, int j, vector<vector<int>> &maze, vector<vector<int>> visited, int n){
        if(i >= n || i < 0){
            return false;
        }
        if(j >= n || j < 0){
            return false;
        }
        if(visited[i][j] == 1){
            return false;
        }
        if(maze[i][j] == 0){
            return false;
        }
        return true;
    }
    void recursion(int i, int j, vector<vector<int>> &maze, int n, vector<vector<int>> &visited, string str = ""){
        if(i == n-1 && j == n-1){
            allPaths.push_back(str);
            return;
        }
        for(int a = 0; a < 4; a++){
            int new_i = i + dx[a];
            int new_j = j + dy[a];
            if(is_safe(new_i, new_j, maze, visited, n)){
                visited[new_i][new_j] = 1;
                recursion(new_i, new_j, maze, n, visited, str + dir[a]);
                visited[new_i][new_j] = 0;
            }
        }
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[0][0] == 0 || m[n-1][n-1] == 0){
            return allPaths;
        }
        vector<vector<int>> visited(n, vector<int>(n, 0));
        visited[0][0] = 1;
        recursion(0, 0, m, n, visited);
        return allPaths;
    }
};
