class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
    // Create a min heap priority queue to store the cell coordinates and the maximum absolute difference in heights
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
    // Get the number of rows and columns of the 2D array
    int rows = heights.size(), cols = heights[0].size();
        
    // Create a 2D vector to store the minimum effort required to reach each cell
    vector<vector<int>> dist(rows, vector<int>(cols, 1e9));
        
    // Create arrays to store the row and column changes for the up, down, left, and right movements
    int rowChanges[] = {-1, 0, 1, 0};
    int colChanges[] = {0, 1, 0, -1};
        
    // Add the starting cell to the priority queue with an initial effort of 0
    pq.push({0, {0, 0}});
        
    // Continue the loop until the priority queue is empty
    while(!pq.empty()) {
        // Get the cell with the smallest effort from the priority queue
        auto cell = pq.top(); pq.pop();
        int maxDiff = cell.first;
        int currRow = cell.second.first;
        int currCol = cell.second.second;

        // If the current cell is the bottom-right cell, return the minimum effort
        if(currRow == rows-1 && currCol == cols-1) return maxDiff;
        // Loop through all four possible directions
        for(int i=0; i<4; i++) {
            // Calculate the new row and column for the next movement
            int newRow = currRow + rowChanges[i];
            int newCol = currCol + colChanges[i];
            
            // Check if the new cell is within the boundaries of the grid
            if(newRow >=0 && newRow < rows && newCol >=0 && newCol < cols) {
                // Calculate the effort required to reach the new cell
                int effort = abs(heights[newRow][newCol] - heights[currRow][currCol]);
                int newMaxDiff = max(effort, maxDiff);
                
                // Check if the new effort is less than the current minimum effort to reach the new cell
                if(newMaxDiff < dist[newRow][newCol]) {
                    // Update the minimum effort to reach the new cell
                    dist[newRow][newCol] = newMaxDiff;
                    
                    // Add the new cell to the priority queue
                    pq.push({newMaxDiff, {newRow, newCol}});
                }
            }
        }
    }
    // Return anyting if the destination is not reached
    return 0; 
}

};