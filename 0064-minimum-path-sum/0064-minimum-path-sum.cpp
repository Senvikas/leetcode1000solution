class Solution {
public:
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
        return solveRec(0, 0, m, n, grid, dp);
    }
};