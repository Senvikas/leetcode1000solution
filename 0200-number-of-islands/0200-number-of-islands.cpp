class Solution {
public:
    
    bool valid(int i, int j, vector<vector<char>> &grid){
        int m = grid.size(), n = grid[0].size();
        if(i>=0 && i<m && j>=0 && j<n) return true;
        return false;
    }
    vector<int> row = {1, 0, 0, -1};
    vector<int> col = {0, -1, 1, 0};
    
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis){
        vis[i][j] = 1;
        for(int k=0; k<4; k++){
            int newi = i + row[k], newj = j + col[k];
            if((valid(newi, newj, grid)) && grid[newi][newj] == '1' && !vis[newi][newj]){

                    dfs(newi, newj, grid, vis);

            }
        }
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        
        int cnt = 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        for(int i=0; i<m; i++){
            
            for(int j=0; j<n; j++){
                
                if(grid[i][j] == '1' && !vis[i][j]){
                        cnt++;
                        dfs(i, j, grid, vis);
                }
                
            }
            
        }
        
        return cnt;
    }
};

