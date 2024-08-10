class Solution {
public:
    void findCombos(vector<int> &candidates, vector<vector<int>> &ans, vector<int> subs, int target, int ind, int n){
        if(ind >= n) return;
        if(target == 0){
            ans.push_back(subs);
            return;
        }
        
        if(candidates[ind] <= target){
            subs.push_back(candidates[ind]);
            findCombos(candidates, ans, subs, target-candidates[ind], ind, n);
            subs.pop_back();
        }
        
        findCombos(candidates, ans, subs, target, ind+1, n);
        
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subs;
        
        findCombos(candidates, ans, subs, target, 0, candidates.size());
        
        return ans;
    }
};