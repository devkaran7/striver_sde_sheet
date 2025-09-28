class Solution {
private:
    long long prime;
    long long mod;
    bool rabinKarp(string &s, string &pattern) {
        int n = s.size();
        int m = pattern.size();
        long long hash1 = 0;
        long long hash2 = 0;
        long long currentPrime = 1;
        for (int i = 0; i < m; i++) {
            hash1 = (hash1 + ((s[i] - 'a' + 1) * currentPrime) % mod) % mod;
            hash2 = (hash2 + ((pattern[i] - 'a' + 1) * currentPrime) % mod) % mod;
            currentPrime = (currentPrime * prime) % mod;
        }
        if (hash1 == hash2) return true;
        long long lastPrime = 1;
        for (int i = m; i < n; i++) {
            hash1 = (hash1 + ((s[i] - 'a' + 1) * currentPrime) % mod) % mod;
            hash1 = (hash1 - ((s[i - m] - 'a' + 1) * lastPrime) % mod + mod) % mod;
            hash2 = (hash2 * prime) % mod;
            if (hash1 == hash2) return true;
            currentPrime = (currentPrime * prime) % mod;
            lastPrime = (lastPrime * prime) % mod;
        }
        return false;
    }
public:
    Solution() : prime(31), mod(1e9 + 7) {}
    int repeatedStringMatch(string a, string b) {
        string s = a;
        int count = 1;
        while(s.size() < b.size()) {
            s = s + a;
            count++;
        }
        if (rabinKarp(s, b)) return count;
        s += a;
        count++;
        if (rabinKarp(s, b)) return count;
        return -1;
    }
};

/*

TC -> O(m)
SC -> O(m)

*/
