class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Create a 3D DP table for memoization, initialized to -1
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(health+1, -1)));
        
        // Stack to store the state (x, y, remaining_health)
        stack<tuple<int, int, int>> stk;
        stk.push({0, 0, health});
        
        while (!stk.empty()) {
            auto [x, y, remaining_health] = stk.top();
            stk.pop();
            
            // If the position is out of bounds or no health is left
            if (x < 0 || y < 0 || x >= n || y >= m || remaining_health <= 0) continue;

            // Reduce health if we step on a cell with 1
            if (grid[x][y] == 1) remaining_health--;

            // If we've reached the bottom-right corner, check the remaining health
            if (x == n-1 && y == m-1 && remaining_health >= 1) return true;

            // If this state has been computed before, skip it
            if (dp[x][y][remaining_health] != -1) continue;

            // Mark this state as visited
            dp[x][y][remaining_health] = 1;

            // Push neighboring cells to the stack
            stk.push({x+1, y, remaining_health});
            stk.push({x-1, y, remaining_health});
            stk.push({x, y+1, remaining_health});
            stk.push({x, y-1, remaining_health});
        }

        // If we exhaust the stack without finding a valid path, return false
        return false;
    }
};
