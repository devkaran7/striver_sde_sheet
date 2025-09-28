class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        while(i < n && s[i] == ' '){
            i++;
        }
        if(i == n){
            return 0;
        }
        bool pos = true;
        if(s[i] == '+'){
            pos = true;
            i++;
        }else if(s[i] == '-'){
            pos = false;
            i++;
        }
        long long ans = 0;
        while(i < n && s[i] - '0' <= 9 && s[i] - '0' >= 0){
            ans = ans * 10ll + (s[i] - '0');
            if (pos && ans >= INT_MAX) return INT_MAX;
            if (!pos && -ans <= INT_MIN) return INT_MIN;
            i++;
        }
        if(pos == false){
            ans = -ans;
        }
        return (int) ans;
    }
};

// INT_MAX and INT_MIN abs value is not same
