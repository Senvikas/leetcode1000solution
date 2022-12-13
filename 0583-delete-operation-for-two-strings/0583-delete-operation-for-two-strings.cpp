//approach for this question
// deletion = first.len - lcs, insertion = sec.len - lcs; 

class Solution
{
    public:
       	//approach -> the longest common subseq. of s and rev(s) will be palindrome
        int lcs(string s, string t, int n, int m)
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
            return dp[n][m];
        }

    int longestPalindromeSubseq(string s, string t)
    {
        int n = s.length(), m = t.length();
        return lcs(s, t, n, m);
    }

    int minDistance(string word1, string word2)
    {
        return word1.length() + word2.length() - 2 *(longestPalindromeSubseq(word1, word2));
    }
};