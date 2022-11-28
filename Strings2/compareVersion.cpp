class Solution {
private:
    int compare(string &a, string &b){
        if(a.size() > b.size()){
            return 1;
        }else if(a.size() < b.size()){
            return -1;
        }
        int i = 0;
        while(i < a.size()){
            if(a[i] > b[i]){
                return 1;
            }else if(a[i] < b[i]){
                return -1;
            }
            i++;
        }
        return 0;
    }
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size();
        int m = version2.size();
        int i = 0, j = 0;
        while(i < n || j < m){
            string s = "";
            if(i < n){
                while(i < n && version1[i] != '.'){
                    if(version1[i] != '0' || s.size() != 0){
                        s += version1[i];
                    }
                    i++;
                }
                i++;
            }
            string t = "";
            if(j < m){
                while(j < m && version2[j] != '.'){
                    if(version2[j] != '0' || t.size() != 0){
                        t += version2[j];
                    }
                    j++;
                }
                j++;
            }
            int answer = compare(s,t);
            if(answer != 0){
                return answer;
            }
        }
        return 0;
    }
};
