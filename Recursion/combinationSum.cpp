class Solution {
private:
    void generateSet(int i, vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& ds){
        if(i == candidates.size()){
            if(target == 0){
                result.push_back(ds);
            }
            return;
        }
        generateSet(i+1, candidates, target, result, ds);
        if(target >= candidates[i]){
            ds.push_back(candidates[i]);
            generateSet(i, candidates, target-candidates[i], result, ds);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ds;
        generateSet(0, candidates, target, result, ds);
        return result;
    }
};
