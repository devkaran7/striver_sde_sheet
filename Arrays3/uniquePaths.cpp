int uniquePaths(int m, int n) {
        m--;
        n--;
        long long ans = 1;
        for(int i = 1; i <= min(n, m); i++){
            ans = (ans*(m+n+1-i))/i;
        }
        return (int)ans;
    }
