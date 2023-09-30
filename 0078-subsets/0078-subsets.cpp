class Solution {
public:
    void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> sset, int ind){
        if(nums.size() == ind){
            ans.push_back(sset);
            return;
        }
        
        sset.push_back(nums[ind]);
        solve(nums, ans, sset, ind+1);
        sset.pop_back();
            
        solve(nums, ans, sset, ind+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < (1 << n); ++i) {
            vector<int> subset;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    subset.push_back(nums[j]);
                }
            }
            result.push_back(subset);
        }

        return result;
    }
};