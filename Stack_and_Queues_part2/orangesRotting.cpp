int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int cnt = 0, time = 0, check = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }else if(grid[i][j] == 1){
                    cnt++;
                }
            }
        }
        int di[] = {1, 0, -1, 0};
        int dj[] = {0, 1, 0, -1};
        while(q.empty() == false){
            int tempsize = q.size();
            time++;
            for(int i = 0; i < tempsize; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int a = 0; a < 4; a++){
                    x += di[a];
                    y += dj[a];
                    if(x < m && y < n && x >= 0 && y >= 0 && grid[x][y] == 1){
                        q.push({x, y});
                        grid[x][y] = 2;
                        check++;
                    }
                    x -= di[a];
                    y -= dj[a];
                }
            }
        }
        if(check == cnt){
            return max(0, time-1);
        }else{
            return -1;
        }
    }
