class Solution {
public:
    int longestSubsequence(vector<int>& nums, int &diff) {
        int n=nums.size();
        vector<int> dp(n, 1);
        unordered_map<int, int> mp;
        for(int i=0; i<n; ++i)
        {
            if(mp[nums[i]-diff])
            {
                dp[i]+=mp[nums[i]-diff];
            }
            mp[nums[i]]=dp[i];
        }
        int ans=0;
        for(int i=0; i<n; ++i)
        ans=max(ans, dp[i]);
        return ans;
    }
};