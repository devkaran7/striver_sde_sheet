string reverseWords(string s) {
        int n = s.size();
        int ind = n-1;
        string result = "";
        while(ind >= 0){
            string str = "";
            while(ind >= 0 && s[ind] != ' '){
                str = s[ind] + str;
                ind--;
            }
            if(result.size() != 0 && str.size() != 0){
                result += " ";
            }
            result += str;
            ind--;
        }
        return result;
    }
