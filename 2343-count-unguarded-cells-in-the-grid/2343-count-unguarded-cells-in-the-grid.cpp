class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0)); // Grid for walls, guards, and unguarded areas
        vector<vector<bool>> vis(m, vector<bool>(n, false)); // Visibility grid
        int ans = 0; // Count of unguarded cells
        
        // Mark guards and walls in the grid
        for (auto& cords : guards) {
            int x = cords[0], y = cords[1];
            grid[x][y] = 1; // Guard
        }
        for (auto& cords : walls) {
            int x = cords[0], y = cords[1];
            grid[x][y] = -1; // Wall
        }

        // Directions: up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Mark visibility from each guard
        for (auto& guard : guards) {
            int x = guard[0], y = guard[1];
            for (auto& dir : directions) {
                int nx = x, ny = y;
                while (true) {
                    nx += dir.first;
                    ny += dir.second;

                    // Stop if out of bounds, hits a wall, or another guard
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 0)
                        break;

                    vis[nx][ny] = true; // Mark cell as visible
                }
            }
        }

        // Count unguarded cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && !vis[i][j]) {
                    ans++; // Cell is unguarded
                }
            }
        }

        return ans;
    }
};
