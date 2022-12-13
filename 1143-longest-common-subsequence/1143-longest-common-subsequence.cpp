class Solution
{
    public:
        int f(string s, string t, int ind1, int ind2, vector<vector < int>> &dp)
        {
            if (ind1 == 0 || ind2 == 0) return 0;

            if (dp[ind1][ind2] != -1) return dp[ind1][ind2];
            if (s[ind1 - 1] == t[ind2 - 1]) return dp[ind1][ind2] = 1 + f(s, t, ind1 - 1, ind2 - 1, dp);
            else return dp[ind1][ind2] = max(f(s, t, ind1 - 1, ind2, dp), f(s, t, ind1, ind2 - 1, dp));
           	//return dp[ind1][ind2];
        }

    int longestCommonSubsequence(string s, string t)
    {
        int n = s.length(), m = t.length();

       	//memoization    (must learn about shifting of the index in this question)      
        /*       vector<vector < int>> dp(n + 1, vector<int> (m + 1, -1));
                return f(s, t, n, m, dp); */

       	//space opti
        /*    vector<vector < int>> dp(n + 1, vector<int> (m + 1, 0));
             for (int i = 1; i <= n; i++)
             {
                 for (int j = 1; j <= m; j++)
                 {
                     if (s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                     else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                 }
             }

             return dp[n][m];          */
        int k = max(n, m);
        vector<int> prev(k + 1, 0), curr(k + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1]) curr[j] = 1 + prev[j - 1];
                else curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }

        return prev[m];
    }
};