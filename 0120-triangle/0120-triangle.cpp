class Solution {
public:
    int tabulation(vector<vector<int>> &triangle){
        int rows = triangle.size();
        vector<vector<int>> dp(rows, vector<int>(rows, 0));

        //base case -> if(i == rows-1) return dp[i][j] = tr[i][j];
        for(int col=0; col<rows; col++){
            dp[rows-1][col] = triangle[rows-1][col];
        }

        for(int row=rows-2; row>=0; row--){
            for(int col=0; col<=row; col++){
                int down = dp[row+1][col];
                int diag = dp[row+1][col+1];

                dp[row][col] = min(down, diag) + triangle[row][col];
            }
        }

        return dp[0][0];

    }
    
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
        //return solve(triangle, 0, 0);
        
        return tabulation(triangle);
    }
};