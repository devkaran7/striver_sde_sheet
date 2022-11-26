int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr, arr + n);
    	sort(dep, dep + n);
    	int currentPlatforms = 0;
    	int maxPlatforms = 0;
    	int i = 0, j = 0;
    	while(i < n){
    	    if(arr[i] <= dep[j]){
    	        currentPlatforms++;
    	        i++;
    	    }else{
    	        currentPlatforms--;
    	        j++;
    	    }
    	    maxPlatforms = max(maxPlatforms, currentPlatforms);
    	}
    	return maxPlatforms;
    }
