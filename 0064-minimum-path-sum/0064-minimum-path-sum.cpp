class Solution {
public:
    int m, n;
    int solve(vector<vector<int>>&g, int i, int j,vector<vector<int>>&dp)
    {
        if(i==0 && j==0) return dp[i][j] = g[i][j];
        
        if(i<0 || j<0) return 1e6;
        if(dp[i][j] != -1) return dp[i][j];
        int l = g[i][j] + solve(g, i, j-1,dp);
        int r = g[i][j] + solve(g, i-1, j,dp);

        return dp[i][j] = min(l, r);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(), vector<int>(grid[0].size(), 0));
        //return solve(grid, grid.size()-1, grid[0].size()-1, dp);
        
        m = grid.size(), n = grid[0].size();
        dp[0][0] = grid[0][0];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0 && j > 0) {
                    dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
                } else if (i > 0) {
                    dp[i][j] = grid[i][j] + dp[i-1][j];
                } else if (j > 0) {
                    dp[i][j] = grid[i][j] + dp[i][j-1];
                }
            }
        }
        
        
        /*
        vector<int> prev(n, 0);
        for(int i=0; i<n; i++) prev[i] = grid[0][i];
        
        for(int i=1; i<m; i++){
            vector<int> temp(n, 0);
            for(int j=0; j<n; j++){
                if(i==0 && j==0) dp[i][j] = grid[0][0];
                else{
                    int l = 0, r = 0;
                    if(j>0) l = grid[i][j] + temp[j-1];
                    if(i>0) r = grid[i][j] + temp[j];
                    dp[i][j] = min(l, r);
                }
            }
            prev = temp;
        }
        */
        
        
        return dp[m-1][n-1];
    }
};