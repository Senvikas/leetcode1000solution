class Solution
{
    public:
        int numEnclaves(vector<vector < int>> &g)
        {
            int n = g.size();
            int m = g[0].size();
            int vis[501][501] = { 0 };
            queue<pair<int, int>> q;
            int dr[4] = { -1,
                0,
                1,
                0
            };
            int dc[4] = { 0,
                1,
                0,
                -1
            };

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                    {
                        if (g[i][j])
                        {
                            vis[i][j] = 1;
                            q.push({ i,
                                j });
                        }
                    }
                }
            }

            while (!q.empty())
            {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && g[nr][nc] == 1)
                    {
                        q.push({ nr,
                            nc });
                        vis[nr][nc] = 1;
                    }
                }
            }
            int cnt = 0;
            for (int i = 1; i < n - 1; i++)
            {
                for (int j = 1; j < m - 1; j++)
                {
                    if (!vis[i][j] && g[i][j]) cnt++;
                }
            }

            return cnt;
        }
};