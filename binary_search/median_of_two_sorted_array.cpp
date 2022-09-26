double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int m = a.size();
        int n = b.size();
        if(n > m){
            return findMedianSortedArrays(b, a);
        }
        int low = 0;
        int high = n;
        int al = INT_MIN;
        int bl = INT_MIN;
        int ar = INT_MAX;
        int br = INT_MAX;
        while(high >= low){
            int cut1 = (high + low)/2;
            int cut2 = (m+n+1)/2 - cut1;
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
        if((m+n)%2 == 0){
            return (double)(max(al, bl) + min(ar, br))/2;
        }
        return (double)max(al, bl);
}
