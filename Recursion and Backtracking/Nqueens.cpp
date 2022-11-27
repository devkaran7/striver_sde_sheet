bool is_possible(int i, int j, int n, vector<int> &left, vector<int> &upd, vector<int> &lwd){
    if(left[i] == 1){
        return false;
    }
    if(upd[i+j] == 1){
        return false;
    }
    if(lwd[n-1+i-j] == 1){
        return false;
    }
    return true;
}

bool rec(int i, int n, vector<vector<int>> &arr, vector<int> &left, vector<int> &upd, vector<int> &lwd){
    if(i == n){
        return true;
    }
    for(int j = 0; j < n; j++){
        if(is_possible(j, i, n, left, upd, lwd)){
            arr[j][i] = 1;
            left[j] = 1;
            upd[i+j] = 1;
            lwd[n-1+j-i] = 1;
            if(rec(i+1, n, arr, left, upd, lwd)){
                return true;
            }
            arr[j][i] = 0;
            left[j] = 0;
            upd[i+j] = 0;
            lwd[n-1+j-i] = 0;
        }
    }
    return false;
}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<int> left(n, 0);
    vector<int> upd(2*n-1, 0);
    vector<int> lwd(2*n-1, 0);
    bool ans = rec(0, n, board, left, upd, lwd);
    debug(ans)
    for(auto it : board){
        for(auto jt : it){
            cout << jt << " ";
        }
        br
    }
}
