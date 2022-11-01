class Solution
{
    void dfs(vector<int> &ans, vector<vector< int>> &grid, int m, int n, int i, int j, int start)
    {
        if (i == m)
        {
            ans[start] = j;
            return;
        }
        if (grid[i][j] == 1)
        {
            if (j + 1 < n && grid[i][j + 1] == 1)
            {
                dfs(ans, grid, m, n, i + 1, j + 1, start);
            }
        }
        else
        {
            if (j - 1 >= 0 && grid[i][j - 1] == -1)
            {
                dfs(ans, grid, m, n, i + 1, j - 1, start);
            }
        }
        return;
    }

    public:
        vector<int> findBall(vector<vector < int>> &grid)
        {
            int m = grid.size();
            int n = grid[0].size();
            vector<int> ans(n, -1);
            int i = 0;
            for (int j = 0; j < n; j++)
            {
                dfs(ans, grid, m, n, i, j, j);
            }
            return ans;
        }
};