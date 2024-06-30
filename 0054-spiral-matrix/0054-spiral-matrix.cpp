class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        
        int rows = 0, rowe = m - 1, cols = 0, cole = n - 1;
        
        while (rows <= rowe && cols <= cole) {
            // Traverse from left to right along the top row
            for (int col = cols; col <= cole; col++) {
                ans.push_back(matrix[rows][col]);
            }
            rows++;
            
            // Traverse from top to bottom along the right column
            for (int row = rows; row <= rowe; row++) {
                ans.push_back(matrix[row][cole]);
            }
            cole--;
            
            // Traverse from right to left along the bottom row, if rows is still within bounds
            if (rows <= rowe) {
                for (int col = cole; col >= cols; col--) {
                    ans.push_back(matrix[rowe][col]);
                }
                rowe--;
            }
            
            // Traverse from bottom to top along the left column, if cols is still within bounds
            if (cols <= cole) {
                for (int row = rowe; row >= rows; row--) {
                    ans.push_back(matrix[row][cols]);
                }
                cols++;
            }
        }
        
        return ans;
    }
};
