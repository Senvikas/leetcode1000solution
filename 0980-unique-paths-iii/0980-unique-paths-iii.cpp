class Solution
{
    public:
        int n, m, srx, sry, endx, endy, paths, ans;

    void dfs(int i, int j, vector<vector < int>> g, int path)
    {
        if (i < 0 || j < 0 || i >= n || j >= m || g[i][j] == -1) return;
        if (i == endx && j == endy && path == paths)
        {
            ans++;
            return;
        }
        g[i][j] = -1;
        dfs(i, j - 1, g, path + 1);
        dfs(i - 1, j, g, path + 1);
        dfs(i, j + 1, g, path + 1);
        dfs(i + 1, j, g, path + 1);
    }
    int uniquePathsIII(vector<vector < int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        paths = m * n;
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    srx = i;
                    sry = j;
                }
                else if (grid[i][j] == 2)
                {
                    endx = i;
                    endy = j;
                }
                else if (grid[i][j] == -1)
                {
                    paths--;
                }
            }
        }
        dfs(srx, sry, grid, 1);
        return ans;
    }
};