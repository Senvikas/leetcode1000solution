class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;
    int solve(vector<vector<int>> &grid, int i1, int j1, int i2, int j2){
        // out of grid
        if(i1 > m || j1 < 0 || j1 >= n || j2 < 0 || j2 >= n) return 0;
        if(i1 == m) return 0;
        
        //if already calculated
        if(dp[i1][j1][j2] != -1) return dp[i1][j1][j2];
        
        // both are in same cell
        int ans;
        if(j1 == j2) ans = grid[i1][j1];
        else ans = grid[i1][j1] + grid[i2][j2];
        
        // three movements
        int collect = INT_MIN;
        for(int i=-1; i<2; i++){
            for(int j=-1; j<2; j++){
                collect = max(collect, solve(grid, i1+1, j1+i, i2+1, j2+j));
            }
        }
        return dp[i1][j1][j2] = ans + collect;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));

        // Base case
        for(int j1 = 0; j1 < n; j1++) {
            for(int j2 = 0; j2 < n; j2++) {
                if(j2 == j1)
                    dp[m - 1][j1][j2] = grid[m - 1][j1];
                else 
                    dp[m - 1][j1][j2] = grid[m - 1][j1] + grid[m - 1][j2];
            }
        }

        for(int i = m - 2; i >= 0; i--) {
            for(int j1 = 0; j1 < n; j1++) {
                for(int j2 = 0; j2 < n; j2++) {
                    // Both are in the same cell
                    int ans;
                    if(j1 == j2) ans = grid[i][j1];
                    else ans = grid[i][j1] + grid[i][j2];

                    // Three movements
                    int collect = INT_MIN;
                    for(int mj1 = -1; mj1 <= 1; mj1++) {
                        for(int mj2 = -1; mj2 <= 1; mj2++) {
                            if(j1 + mj1 >= 0 && j1 + mj1 < n && j2 + mj2 >= 0 && j2 + mj2 < n)
                                collect = max(collect, dp[i + 1][j1 + mj1][j2 + mj2]);
                        }
                    }
                    dp[i][j1][j2] = ans + collect;
                }
            }
        }

        return dp[0][0][n - 1];
    }

};