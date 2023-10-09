class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MIN)); // Initialize with INT_MIN
        
        // Fill first row
        for(int i = 0; i < n; i++) {
            dp[0][i] = max(nums1[0] * nums2[i], i > 0 ? dp[0][i-1] : nums1[0] * nums2[i]);
        }
        
        // Fill first column
        for(int i = 0; i < m; i++) {
            dp[i][0] = max(nums1[i] * nums2[0], i > 0 ? dp[i-1][0] : nums1[i] * nums2[0]);
        }
        
        // Filling the entire dp
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                int multi = nums1[i] * nums2[j];
                dp[i][j] = max(multi, max(dp[i-1][j], max(dp[i][j-1], dp[i-1][j-1] + multi)));
            }
        }
        
        return dp[m-1][n-1];
    }
};
