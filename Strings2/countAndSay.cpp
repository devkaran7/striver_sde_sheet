string countAndSay(int n) {
    string result = "1";
    for(int i = 0; i < n-1; i++){
        int m = result.size();
        string newString = "";
        int j = 0;
        while(j < m){
            int k = j+1;
            while(k < m && result[j] == result[k]){
                k++;
            }
            newString += to_string(k-j);
            newString += result[j];
            j = k;
        }
        result = newString;
    }
    return result;
}
