vector<int> Solution::dNums(vector<int> &A, int B) {
    int n = A.size();
    unordered_map<int, int> mp;
    for(int i = 0; i < B; i++){
        mp[A[i]]++;
    }
    vector<int> result;
    result.push_back(mp.size());
    for(int i = B; i < n; i++){
        int prev = i-B;
        int next = i;
        mp[A[prev]]--;
        if(mp[A[prev]] == 0){
            mp.erase(mp.find(A[prev]));
        }
        mp[A[next]]++;
        result.push_back(mp.size());
    }
    return result;
}
