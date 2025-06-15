class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> combination;
        backtrack(candidates, result, combination, 0, target);
        return result;
    }

private:
    void backtrack(vector<int> &candidates, vector<vector<int>> &result, vector<int> combination, int index, int remTarget)
    {
        if(remTarget == 0)
        {
            result.push_back(combination);
            return;
        }

        for(int ind = index; ind < candidates.size(); ind++)
        {
            if(ind > index && candidates[ind-1] == candidates[ind])
                continue;

            if(remTarget < candidates[ind])
                break;

            combination.push_back(candidates[ind]);
            backtrack(candidates, result, combination, ind+1, remTarget-candidates[ind]);
            combination.pop_back();
        }
        return;
    }
};