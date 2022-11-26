class Solution
{
private:
    void recursion(int i, int n, vector<int> &arr, vector<int> &ds, int sum = 0){
        if(i == n){
            ds.push_back(sum);
            return;
        }
        recursion(i+1, n, arr, ds, sum + arr[i]);
        recursion(i+1, n, arr, ds, sum);
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ds;
        recursion(0, N, arr, ds);
        return ds;
    }
};
