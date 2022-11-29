class Solution
{
private:
    bool find(string &s, vector<string> &dictionary){
        int n = dictionary.size();
        for(int i = 0; i < n; i++){
            if(dictionary[i] == s) return true;
        }
        return false;
    }
public:
    int wordBreak(string s, vector<string> &dictionary) {
        //code here
        int n = s.size();
        int dp[n+1] = {0};
        dp[n] = 1;
        for(int i = n-1; i >= 0; i--){
            string temp = "";
            for(int j = i; j < n; j++){
                temp += s[j];
                if(find(temp, dictionary)){
                    dp[i] = max(dp[i], dp[j+1]);
                }
            }
        }
        return dp[0];
    }
};
