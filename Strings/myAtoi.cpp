class Solution {
private:
    int getNum(string &s, bool isNeg){
        long long x = isNeg ? -1 : 1;
        long long ans = 0;
        for(int i = s.size() - 1; i >= 0; i--){
            ans = ans + (s[i] - '0') * x;
            if(ans >= INT_MAX || x >= INT_MAX){
                return INT_MAX;
            }else if(ans <= INT_MIN || x <= INT_MIN){
                return INT_MIN;
            }
            x = x * 10ll;
        }
        return (int) ans;
    }
public:
    int myAtoi(string s) {
        int ind = 0;
        int n = s.size();
        string result = "";
        int neg = 0;
        while(ind < n){
            if((s[ind] == '-' || s[ind] == '+') && (neg == 0)){
                if(s[ind] == '+'){
                    neg++;
                }
                neg++;
            }else if(s[ind] == '0'){
                if(result.size() != 0){
                    result += s[ind];
                }else{
                    neg += 2;
                }
            }else if(s[ind] - '0' <= 9 && s[ind] - '0' >= 1){
                result += s[ind];
                neg += 2;
            }else if(s[ind] == ' ' && result.size() == 0 && neg == 0){
                ind++;
                continue;
            }else{
                break;
            }
            ind++;
        }
        return getNum(result, neg%2);
    }
};
