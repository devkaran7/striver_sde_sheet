class Solution {
private:
    int getNextInt(string &s, int &i) {
        int integer = 0;
        while(i < s.size() && s[i] != '.') {
            integer *= 10;
            integer += (s[i] - '0');
            i++;
        }
        if (i < s.size()) i++;
        return integer;
    }
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        while(i < version1.size() || j < version2.size()) {
            int first = getNextInt(version1, i);
            int second = getNextInt(version2, j);
            if (first < second) {
                return -1;
            } else if (second < first) {
                return 1;
            }
        }
        return 0;
    }
};

/*

v1 -> 1

v2 -> 1

*/
