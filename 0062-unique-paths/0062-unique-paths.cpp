class Solution {
public:
    int f(int m, int n, vector<vector<int>> &dp){
        if(m==0 && n==0) return 1;
        if(dp[m][n] != -1) return dp[m][n];
        int u=0,l=0;
        if(m-1>=0) u = f(m-1, n, dp);
        if(n-1>=0) l = f(m, n-1, dp);
        return dp[m][n] = u+l;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        //return f(m-1, n-1, dp);
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};