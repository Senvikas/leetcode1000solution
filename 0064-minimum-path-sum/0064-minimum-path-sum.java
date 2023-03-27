class Solution {

    public int minPathSum(int[][] grid) {
        for (int r = 0; r < grid.length; r++) {
            for (int c = 0; c < grid[0].length; c++) {
                if (
                    r == 0 && c == 0
                ) continue; //skip the initial point (0,0)
                if (
                    r == 0
                ) grid[r][c] += grid[r][c - 1]; else if ( //first row elements: possible only through the previous column(c-1)
                    c == 0
                ) grid[r][c] += grid[r - 1][c]; else { //first column elements: possible only through the previous row(r-1)
                    grid[r][c] += Math.min(grid[r - 1][c], grid[r][c - 1]); //add the min of the left and upper value, to find min cost
                }
            }
        }
        return grid[grid.length - 1][grid[0].length - 1]; //ans is the last element: minimized cost
    }
}
