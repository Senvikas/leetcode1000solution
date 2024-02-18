class Solution {
public:
    int tabulation(vector<vector<int>> &grid){
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        
        //base case
        dp[0][0] = grid[0][0];
        
        for(int row=1; row<rows; row++)
            dp[row][0] += dp[row-1][0] + grid[row][0];
        
        for(int col=1; col<cols; col++)
            dp[0][col] += dp[0][col-1] + grid[0][col];
        
        for(int row=1; row<rows; row++){
            for(int col=1; col<cols; col++){
                dp[row][col] = grid[row][col] + min(dp[row-1][col], dp[row][col-1]);
            }
        }
        
        return dp[rows-1][cols-1];
    }
    
    int solveRec(int row, int col, int rows, int cols, vector<vector<int>> &grid, vector<vector<int>> &dp){
        //base case
        if(row == rows-1 && col == cols-1) return grid[row][col];
        if(row >= rows || col >= cols) return 1e8;
        
        if(dp[row][col] != -1) return dp[row][col];      //2nd step
        
        //I'll do one part + Remaining Rec
        int down = grid[row][col]  +  solveRec(row+1, col, rows, cols, grid, dp);
        int right = grid[row][col]  +  solveRec(row, col+1, rows, cols, grid, dp);
        
        int maxSum = min(down, right);
        
        return dp[row][col] = maxSum;           //1st step
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));     //0th step
        //return solveRec(0, 0, m, n, grid, dp);
        
        
        return tabulation(grid);
    }
};