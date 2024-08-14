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
        if(og[0][0] == 1) return 0;
        vector<vector<int>> dp(og.size(), vector<int>(og[0].size(), 0));
        //return f(og, og.size()-1, og[0].size()-1, dp);
        dp[0][0] = 1;
        for(int i=0; i<og.size(); i++){
            for(int j=0; j<og[0].size(); j++){
                if(i==0 && j==0) continue;
                int u = 0, l = 0;
                
                if(i-1>=0) u = og[i][j] == 0 ? dp[i-1][j] : 0;
                if(j-1>=0) l = og[i][j] == 0 ? dp[i][j-1] : 0;
                dp[i][j] = u+l;
            }
        }
        return dp[og.size()-1][og[0].size()-1];
    }
};