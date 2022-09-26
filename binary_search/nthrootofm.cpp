double power(double num, int n){
    double ans = 1;
    for(int i = 1; i <= n; i++){
        ans = ans * num;
    }
    return ans;
}

double findNthRootOfM(int n, int m) {
    double low = 0;
    double high = m;
    while(high - low > 0.0000001){
        double mid = (high + low) / 2.0;
        if(power(mid, n) > m){
            high = mid;
        }else{
            low = mid;
        }
    }
    return low;
}
