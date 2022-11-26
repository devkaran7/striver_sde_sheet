class Solution {
private:
    void generateUniqueSets(vector<int>& candidates, int target, int ind, vector<int>& ds, vector<vector<int>>& result){
        if(target == 0){
            result.push_back(ds);
            return;
        }
        for(int i = ind; i < candidates.size(); i++){
            if(i == ind || candidates[i] != candidates[i-1]){
                if(target < candidates[i]){
                    break;
                }
                ds.push_back(candidates[i]);
                generateUniqueSets(candidates, target-candidates[i], i+1, ds, result);
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        generateUniqueSets(candidates, target, 0, ds, result);
        return result;
    }
};
