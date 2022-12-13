class Solution
{
    public:
        int f(string s, string t, int ind1, int ind2, vector<vector < int>> &dp)
        {
            if (ind1 < 0 || ind2 < 0) return 0;
            if (ind1 == 0 && ind2 == 0) return s[ind1] == t[ind2];
            if (dp[ind1][ind2] != -1) return dp[ind1][ind2];
            if (s[ind1] == t[ind2]) return dp[ind1][ind2] = 1 + f(s, t, ind1 - 1, ind2 - 1, dp);
            else return dp[ind1][ind2] = max(f(s, t, ind1 - 1, ind2, dp), f(s, t, ind1, ind2 - 1, dp));
           	//return dp[ind1][ind2];
        }

    int longestCommonSubsequence(string s, string t)
    {
        int n = s.length(), m = t.length();

        /*    vector<vector < int>> dp(n + 1, vector<int> (m + 1, -1));
              return f(s, t, n - 1, m - 1, dp);           */

        vector<vector < int>> dp(n, vector<int> (m, 1));
        for (int ind2 = 0; ind2 < m; ind2++)
        {
            int val = s[0] == t[ind2];
            if (val) break;
            dp[0][ind2] = 0;
        }
        for (int ind1 = 0; ind1 < n; ind1++)
        {
            int val = s[ind1] == t[0];
            if (val) break;
            dp[ind1][0] = 0;
        }

        for (int ind1 = 1; ind1 < n; ind1++)
        {
            for (int ind2 = 1; ind2 < m; ind2++)
            {
               	//matched
                if (s[ind1] == t[ind2])
                {
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                }
                else
                    dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
            }
        }

        return dp[n - 1][m - 1];
    }
};