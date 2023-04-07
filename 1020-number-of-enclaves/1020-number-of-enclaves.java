class Solution {

    public int bfs(int i, int j, int[][] grid, int[][] vis, int m, int n) {
        int count = 0;
        if ((i < 0 || i >= m) || (j < 0 || j >= n)) {
            return 0;
        } else {
            if (vis[i][j] == 0) {
                if (grid[i][j] == 1) {
                    vis[i][j] = 1;
                    count += 1;
                    count += bfs(i + 1, j, grid, vis, m, n);
                    count += bfs(i - 1, j, grid, vis, m, n);
                    count += bfs(i, j + 1, grid, vis, m, n);
                    count += bfs(i, j - 1, grid, vis, m, n);
                    return count;
                }
            } else {
                return 0;
            }
        }
        return count;
    }

    public int numEnclaves(int[][] grid) {
        int i = 0, j = 0, m = grid.length, n = grid[0].length;
        int totalones = 0;
        int[][] vis = new int[m][n];
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    totalones += 1;
                }
            }
        }
        for (i = 0; i < m; i++) {
            if (vis[i][0] == 0) {
                if (grid[i][0] == 1) {
                    int reachable = bfs(i, 0, grid, vis, m, n);
                    // System.out.println("reachable1: "+reachable);
                    totalones -= reachable;
                }
            }
        }
        for (i = 0; i < m; i++) {
            if (vis[i][n - 1] == 0) {
                if (grid[i][n - 1] == 1) {
                    int reachable = bfs(i, n - 1, grid, vis, m, n);
                    //  System.out.println("reachable2: "+reachable);
                    totalones -= reachable;
                }
            }
        }
        for (j = 0; j < n; j++) {
            if (vis[0][j] == 0) {
                if (grid[0][j] == 1) {
                    int reachable = bfs(0, j, grid, vis, m, n);
                    // System.out.println("reachable3: "+reachable);
                    totalones -= reachable;
                }
            }
        }
        for (j = 0; j < n; j++) {
            if (vis[m - 1][j] == 0) {
                if (grid[m - 1][j] == 1) {
                    int reachable = bfs(m - 1, j, grid, vis, m, n);
                    //System.out.println("reachable4: "+reachable);
                    totalones -= reachable;
                }
            }
        }
        return totalones;
    }
}
