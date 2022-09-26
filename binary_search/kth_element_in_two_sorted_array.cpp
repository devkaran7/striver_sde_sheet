int kthElement(int a[], int b[], int m, int n, int k)
    {
        if(n > m){
            return kthElement(b, a, n, m, k);
        }
        int low = max(0, k-m);
        int high = min(k, n);
        int al = INT_MIN;
        int bl = INT_MIN;
        int ar = INT_MAX;
        int br = INT_MAX;
        while(high >= low){
            int cut1 = (high + low)/2;
            int cut2 = k - cut1;
            if(cut2 > 0){
                al = a[cut2-1];
            }else{
                al = INT_MIN;
            }
            if(cut2 < m){
                ar = a[cut2];
            }else{
                ar = INT_MAX;
            }
            if(cut1 > 0){
                bl = b[cut1-1];
            }else{
                bl = INT_MIN;
            }
            if(cut1 < n){
                br = b[cut1];
            }else{
                br = INT_MAX;
            }
            if(br < al){
                low = cut1 + 1;
            }else if(bl > ar){
                high = cut1 - 1;
            }else{
                break;
            }
        }
        return max(al ,bl);
    }
