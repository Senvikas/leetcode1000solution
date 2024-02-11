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
        m = grid.size();
        n = grid[0].size();
        dp.assign(m, vector<vector<int>>(m, vector<int>(n, -1)));
        //dp = vector<vector<vector<int>>>>(m, vector<vector<int>>(m, vector<int>(n, -1)));
        return solve(grid, 0, 0, 0, n - 1);
    }

};