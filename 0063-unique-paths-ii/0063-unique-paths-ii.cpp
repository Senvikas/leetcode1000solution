class Solution {
public:
    int f(vector<vector<int>> &og, int m, int n, vector<vector<int>> &dp){
        if(og[m][n] == 1) return 0;
        if(m == 0 && n == 0) return 1;
        
        if(dp[m][n] != -1) return dp[m][n];
        int u = 0, l = 0;
        
        if(m-1>=0) u = f(og, m-1, n, dp);
        if(n-1>=0) l = f(og, m, n-1, dp);
        
        return dp[m][n] = u+l;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
    
        vector<vector<int>> dp(og.size(), vector<int>(og[0].size(), -1));
        return f(og, og.size()-1, og[0].size()-1, dp);
    }
};