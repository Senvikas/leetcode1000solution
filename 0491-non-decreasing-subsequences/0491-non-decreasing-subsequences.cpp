class Solution {
public:
    void update(set<vector<int>>&ans, vector<int>v, vector<int>nums, int l)
    {
        for(int i=l+1; i<nums.size(); i++)
        {
            if(nums[i]>=v[v.size()-1])
            {
                v.push_back(nums[i]);
                ans.insert(v);
                update(ans, v, nums, i);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>>ans;

        for(int i=0; i<nums.size()-1; i++)
        {
            vector<int>v;
            v.push_back(nums[i]);
            update(ans, v, nums,  i);
        }
        vector<vector<int>>res;
        for(auto it:ans)
        {
            res.push_back(it);
        }
        return res;
    }
};