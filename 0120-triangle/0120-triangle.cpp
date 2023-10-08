class Solution {
public:
    int rows;
    vector<vector<int>> dp;
    int solve(vector<vector<int>> &tr, int i, int j){
        if(i == rows-1) return dp[i][j] = tr[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
         
        int d = tr[i][j] + solve(tr, i+1, j);
        int dig = tr[i][j] + solve(tr, i+1, j+1);
        
        return dp[i][j] = min(d, dig);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        rows = triangle.size();
        dp = vector<vector<int>>(rows, vector<int>(rows, -1));
        return solve(triangle, 0, 0);
    }
};