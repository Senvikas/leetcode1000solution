class Solution {
public:
    void solve(vector<int> &candi, vector<vector<int>> &ans, vector<int> tmp, int t, int ind){
        if(ind >= candi.size() || t < 0) return ;
        
        if(t == 0){
            ans.push_back(tmp);
            return;
        }
        
        //choose & not to choose
        if(candi[ind] <= t){
            t -= candi[ind];
            tmp.push_back(candi[ind]);
            solve(candi, ans, tmp, t, ind);
            t += candi[ind];
            tmp.pop_back();
        }
        
        solve(candi, ans, tmp, t, ind+1);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        solve(candidates, ans, {}, target, 0);
        return ans;
    }
};