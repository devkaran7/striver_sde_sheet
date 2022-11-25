vector<int> Solution::repeatedNumber(const vector<int> &nums) {
    long long n = nums.size();
    long long sum = 0;
    long long sumOfSquares = 0;
    for(auto num : nums){
        long long x = num;
        sum += x;
        sumOfSquares += x * x;
    }
    long long aminusb = sum - (n*(n+1))/2ll;
    long long aplusb = (sumOfSquares - (n * (n+1) * (2ll*n+1))/6ll)/aminusb;
    vector<int> answer;
    long long a = (aminusb + aplusb)/2ll;
    answer.push_back(a);
    long long b = (aplusb - aminusb)/2ll;
    answer.push_back(b);
    return answer;
}
