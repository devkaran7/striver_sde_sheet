class Solution {
private:
    bool ispalin(string s, int i, int j){
        while(j > i){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void partitionutil(vector<vector<string>>& result, vector<string>& ds, string s, int ind, int n){
        if(ind == n){
            result.push_back(ds);
            return;
        }
        for(int i = ind + 1; i <= n; i++){
            if(ispalin(s, ind, i-1)){
                ds.push_back(s.substr(ind, i-ind));
                partitionutil(result, ds, s, i, n);
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> ds;
        int n = s.size();
        partitionutil(result, ds, s, 0, n);
        return result;
    }
};
