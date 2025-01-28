class Solution {
private:
    int countFishes(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c) {
        if (r == -1 || r == grid.size() || c == -1 || c == grid[0].size() || !grid[r][c] || visited[r][c]) {
            return 0;
        }
        visited[r][c] = true;
        return grid[r][c] +
            countFishes(grid, visited, r, c + 1) +
            countFishes(grid, visited, r, c - 1) +
            countFishes(grid, visited, r + 1, c) +
            countFishes(grid, visited, r - 1, c);
    }
    
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), result = 0;
        vector visited(m, vector<bool>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] && !visited[i][j]) {
                    result = max(result, countFishes(grid, visited, i, j));
                }
            }
        }
        return result;
    }
};