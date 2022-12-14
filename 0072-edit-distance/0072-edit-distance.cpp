class Solution
{
    public:
        int solve(int i, int j, string &s, string &t, vector<vector < int>> &dp)
        {
            if (i == 0) return j;
            if (j == 0) return i;
            if (dp[i][j] != -1) return dp[i][j];
            if (s[i - 1] == t[j - 1])
                return dp[i][j] = solve(i - 1, j - 1, s, t, dp);

            int insertion = 1 + solve(i, j - 1, s, t, dp);
            int deletion = 1 + solve(i - 1, j, s, t, dp);
            int replace = 1 + solve(i - 1, j - 1, s, t, dp);

            return dp[i][j] = min(insertion, min(deletion, replace));
        }
    int minDistance(string s, string t)
    {
        int n = s.length(), m = t.length();
        /*     vector<vector < int>> dp(n + 1, vector<int> (m + 1, -1));
              return solve(n, m, s, t, dp);             */

        vector<vector < int>> dp(n + 1, vector<int> (m + 1, 0));
        for (int i = 0; i <= n; i++)
            dp[i][0] = i;
        for (int j = 0; j <= m; j++)
            dp[0][j] = j;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                {
                    int insertion = 1 + dp[i][j - 1];
                    int deletion = 1 + dp[i - 1][j];
                    int replace = 1 + dp[i - 1][j - 1];

                    dp[i][j] = min(insertion, min(deletion, replace));
                }
            }
        }
        return dp[n][m];
    }
};