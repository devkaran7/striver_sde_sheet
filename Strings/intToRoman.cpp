private:
    char c[10] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
public:
    string intToRoman(int num) {
        int i = 0;
        int temp = num;
        string s = "";
        while(temp){
            string str = "";
            int digit = temp % 10;
            if(digit <= 3){
                for(int j = 0; j < digit; j++){
                    str += c[i];
                }
            }else if(digit == 4){
                str += c[i];
                str += c[i+1];
            }else if(digit == 9){
                str += c[i];
                str += c[i+2];
            }else{
                str += c[i+1];
                for(int j = 0; j < (digit%5); j++){
                    str += c[i];
                }
            }
            temp = temp / 10;
            i+=2;
            s = str + s;
        }
        return s;
    }
