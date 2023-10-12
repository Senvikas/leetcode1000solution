class Solution {
    public static int solve(int[][] grid, int i1, int j1, int i2, int j2, int[][][][] dp){
        //base case 
        if(i1<0 || j1<0 || i2<0 || j2<0 || grid[i1][j1] == -1 || grid[i2][j2] == -1)
            return (int)-1e8;
        if(i1==0 && j1==0 && i2==0 && j2==0) return grid[i1][j1];
        
        if(dp[i1][j1][i2][j2] != 0) return dp[i1][j1][i2][j2];
        
        int cherries = 0;
        
        // at same spot
        if(i1==i2 && j1==j2) cherries = grid[i1][j1];
        
        //otherwise
        else cherries = grid[i1][j1] + grid[i2][j2];
        
        //4 direction movement
        int hh = solve(grid, i1, j1-1, i2, j2-1, dp);
        int hv = solve(grid, i1, j1-1, i2-1, j2, dp);
        int vh = solve(grid, i1-1, j1, i2, j2-1, dp);
        int vv = solve(grid, i1-1, j1, i2-1, j2, dp);
        
        int maxCollection = cherries + Math.max(Math.max(hh, hv), Math.max(vh, vv));
        return dp[i1][j1][i2][j2] = maxCollection;
    }
    
    public int cherryPickup(int[][] grid) {
        int n = grid.length;
        if(grid[n-1][n-1] == -1 || grid[0][0] == -1) return 0;
        
          int[][][][] dp = new int[n][n][n][n];
        
        int ans = solve(grid, n-1, n-1, n-1, n-1, dp);
        if(ans <= 0) return 0;
        return ans;
    }
}