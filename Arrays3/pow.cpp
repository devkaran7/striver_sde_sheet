class Solution {
private:
    double power(double base, long long n){
        double answer = 1.0;
        while(n){
            if(n % 2){
                answer = answer * base;
                n--;
            }else{
                base = base * base;
                n = n/2;
            }
        }
        return answer;
    }
public:
    double myPow(double x, int n) {
        double answer = power(x, abs(n));
        if(n < 0){
            answer = 1.0/answer;
        }
        return answer;
    }
};
