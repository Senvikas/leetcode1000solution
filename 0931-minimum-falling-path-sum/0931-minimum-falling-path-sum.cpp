class Solution {
public:
    int solve(vector<vector<int>>& arr, int n, int i, int j, vector<vector<int>>& dp)
    {
        if(j<0 || j>=n) return 1e8;
        if(i==n-1) return arr[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int d = arr[i][j] + solve(arr, n, i+1, j, dp);
        int dl = arr[i][j] + solve(arr, n, i+1, j-1, dp);
        int dr = arr[i][j] + solve(arr, n, i+1, j+1, dp);
        
        return dp[i][j] = min(d, min(dl, dr));
    }
    
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr[0].size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans = INT_MAX;
        for(int j=0; j<n; j++)
        {
            ans = min(ans, solve(arr, n, 0, j, dp));
        }
        return ans;
    }
};