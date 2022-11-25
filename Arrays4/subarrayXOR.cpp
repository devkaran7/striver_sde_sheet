int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    unordered_map<int, int> mp;
    int currentXOR = 0;
    int count = 0;
    for(int i = 0; i < n; i++){
        currentXOR = currentXOR ^ A[i];
        count += mp[currentXOR ^ B];
        mp[currentXOR]++;
        if(currentXOR == B){
            count++;
        }
    }
    return count;
}
