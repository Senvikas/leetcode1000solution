class Solution {
public:
    //my code: refactored by chatGpt
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // Initialize queue for BFS
        queue<pair<int, pair<int, int>>> bfsQueue;
        bfsQueue.push({1, {0, 0}});

        // Edge case: if starting or ending point is blocked
        int gridSize = grid.size();
        if(gridSize == 1){
            if(grid[0][0] == 0) return 1;
            return -1;
        }
        if (gridSize > 1 && (grid[0][0] == 1 || grid[gridSize - 1][gridSize - 1] == 1)) return -1;

        // Initialize distance grid with large value
        vector<vector<int>> distance(gridSize, vector<int>(gridSize, 1e9));
        distance[0][0] = 0;

        // Array for movement in 8 directions
        int rowDirection[] = {-1, 0, 1, 0, -1, 1, -1, 1};
        int colDirection[] = {0, 1, 0, -1, 1, 1, -1, -1};

        while (!bfsQueue.empty()) {
            auto current = bfsQueue.front();
            bfsQueue.pop();
            int distanceFromStart = current.first;
            int currentRow = current.second.first;
            int currentCol = current.second.second;

            for (int i = 0; i < 8; i++) {
                int nextRow = currentRow + rowDirection[i];
                int nextCol = currentCol + colDirection[i];

                // Check if next point is within grid and not blocked
                if (nextRow >= 0 && nextRow < gridSize && nextCol >= 0 && nextCol < gridSize && grid[nextRow][nextCol] == 0 && 1 + distanceFromStart < distance[nextRow][nextCol]) {
                    distance[nextRow][nextCol] = 1 + distanceFromStart;
                    if (nextRow == gridSize - 1 && nextCol == gridSize - 1) return 1 + distanceFromStart; // End point reached
                    bfsQueue.push({1 + distanceFromStart, {nextRow, nextCol}});
                }
            }
        }
        return -1;
    }

};