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
        while(ind+1 < nums.size() && nums[ind] == nums[ind+1]) ind++;   
        solve(nums, ans, sset, ind+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        solve(nums, ans, {}, 0);
        return ans;
    }
};