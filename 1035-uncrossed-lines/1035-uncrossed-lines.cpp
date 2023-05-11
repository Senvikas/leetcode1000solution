class Solution {
public:
    int lcs(int n, int m, vector<int>& nums1, vector<int>& nums2,vector<vector<int>>&dp){
        if(m<0 || n<0){
            return 0;
        }
        if(dp[n][m] != -1){
            return dp[n][m];
        }

        dp[n][m] = INT_MIN;
        if(nums1[n] == nums2[m]){
            dp[n][m] = max(dp[n][m],  1+lcs(n-1, m-1, nums1, nums2, dp));
        }

        dp[n][m] = max(dp[n][m], max(lcs(n-1,m,nums1, nums2, dp), lcs(n,m-1,nums1,nums2, dp)));

        return dp[n][m];
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
        return lcs(n-1,m-1,nums1, nums2,dp);

    }
};