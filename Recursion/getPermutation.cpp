string getPermutation(int n, int k) {
        k--;
        vector<int> factorial(n);
        factorial[0] = 1;
        for(int i = 1; i < n; i++){
            factorial[i] = i * factorial[i-1];
        }
        string permutation = "";
        vector<int> visited(n+1, 0);
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= n; j++){
                if(visited[j] == false){
                    if(factorial[n-i-1] <= k){
                        k = k - factorial[n-i-1];
                    }else{
                        visited[j] = true;
                        char nextChar = '0';
                        nextChar += j;
                        permutation += nextChar;
                        break;
                    }
                }
            }
        }
        return permutation;
    }
