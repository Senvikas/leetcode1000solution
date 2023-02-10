class Solution
{
    public:
        int maxDistance(vector<vector < int>> &grid)
        {
            int n = grid.size();
            int dist = 0;
            queue<pair<int, int>> que;
            for (int r = 0; r < n; r++)
                for (int c = 0; c < n; c++)
                    if (grid[r][c] == 1)
                        que.push({ r,
                            c });
            if (que.size() == 0 || que.size() == n *n) return -1;
            while (que.size())
            {
                int m = que.size();
                for (int i = 0; i < m; i++)
                {
                    auto node = que.front();
                    que.pop();
                    int r = node.first, c = node.second;
                    if (r > 0 && grid[r - 1][c] == 0)
                    {
                        grid[r - 1][c] = 1;
                        que.push({ r - 1,
                            c });
                    }
                    if (r + 1 < n && grid[r + 1][c] == 0)
                    {
                        grid[r + 1][c] = 1;
                        que.push({ r + 1,
                            c });
                    }
                    if (c > 0 && grid[r][c - 1] == 0)
                    {
                        grid[r][c - 1] = 1;
                        que.push({ r,
                            c - 1 });
                    }
                    if (c + 1 < n && grid[r][c + 1] == 0)
                    {
                        grid[r][c + 1] = 1;
                        que.push({ r,
                            c + 1 });
                    }
                }
                if (que.size()) dist++;
            }
            return dist;
        }
};