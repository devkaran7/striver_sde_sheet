private:
    int arr[10] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
public:
    vector<int> minPartition(int N)
    {
        // code here
        int total = N;
        vector<int> result;
        int pointer =  9;
        while(pointer != -1){
            while(total >= arr[pointer]){
                result.push_back(arr[pointer]);
                total -= arr[pointer];
            }
            pointer--;
        }
        return result;
    }
