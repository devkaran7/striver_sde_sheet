class Solution {
private:
    long long mod = 1e9 + 7;
    long long power(long long base, long long x){
        long long ans = 1;
        while(x){
            if(x % 2 == 0){
                base = (base * base) % mod;
                x = x / 2;
            }else{
                ans = (ans * base) % mod;
                x--;
            }
        }
        return ans;
    }
    long long blackbox(string &s){
        long long stringHash = 0;
        long long pr = 1;
        for(int i = 0; i < s.size(); i++){
            stringHash = (stringHash + ((s[i] - 'a'+ 1ll) * pr) % mod) % mod;
            pr = (pr * 31ll) % mod;
        }
        return stringHash;
    }
    bool rabin_karp(string &str, string &ptr){
        int n = str.size();
        int m = ptr.size();
        long long patternHash = blackbox(ptr);
        string temp = str.substr(0, m);
        long long stringHash = blackbox(temp);
        long long rightPrime = power(31, m);
        long long leftPrime = 1;
        if(patternHash == stringHash) return true;
        for(int i = m; i < n; i++){
            int nextIndex = i;
            int prevIndex = i-m;
            stringHash = (stringHash - (((str[prevIndex] - 'a' + 1) * leftPrime) % mod) + mod) % mod;
            stringHash = (stringHash + ((str[nextIndex] - 'a' + 1) * rightPrime) % mod) % mod;
            patternHash = (patternHash * 31ll) % mod;
            if(stringHash == patternHash) return true;
            rightPrime = (rightPrime * 31ll) % mod;
            leftPrime = (leftPrime * 31ll) % mod;
        }
        return false;
    }
public:
    int repeatedStringMatch(string a, string b) {
        //use rabin karp
        string s = a;
        int count = 1;
        while(s.size() < b.size()){
            s = s + a;
            count++;
        }
        if(rabin_karp(s, b)) return count;
        s += a;
        if(rabin_karp(s, b)) return count + 1;
        return -1;
    }
};
