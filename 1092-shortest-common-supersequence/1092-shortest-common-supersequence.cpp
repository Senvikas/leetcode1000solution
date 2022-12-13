class Solution
{
    public:

        vector<vector < int>> lcsTable(string s, string t, int n, int m)
        {
            vector<vector < int>> dp(n + 1, vector<int> (m + 1, 0));

            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                    else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
            return dp;
        }

    string shortestCommonSupersequence(string s, string t)
    {
        int n = s.length(), m = t.length();
        vector<vector < int>> dp = lcsTable(s, t, n, m);

        string ans = "";
        int i = n, j = m;

        while (i > 0 && j > 0)
        {
            if (s[i - 1] == t[j - 1])	//using i-1 and j-1 because of shifting of index
            {
                ans += s[i - 1];
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                ans += s[i - 1];
                i--;
            }
            else
            {
                ans += t[j - 1];
                j--;
            }
        }
        while (i > 0)
        {
            ans += s[i - 1];
            i--;
        }
        while (j > 0)
        {
            ans += t[j - 1];
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};