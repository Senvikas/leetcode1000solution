class Solution
{
    public:
        int n;
    int f(int ind, int cb, vector<int> &pr, vector<vector< int>> &dp)
    {
        if (ind >= n) return 0;

        if (dp[ind][cb] != -1) return dp[ind][cb];
        if (cb) return dp[ind][cb] = max(-pr[ind] + f(ind + 1, 0, pr, dp), 0 + f(ind + 1, 1, pr, dp));
        return dp[ind][cb] = max(pr[ind] + f(ind + 2, 1, pr, dp), 0 + f(ind + 1, 0, pr, dp));
    }

    int maxProfit(vector<int> &prices)
    {
        n = prices.size();
        vector<vector < int>> dp(n + 2, vector<int> (2, 0));
       	//return f(0, 1, prices, dp);

        for (int ind = n - 1; ind >= 0; ind--)
        {
                // removed cb cond, when cb = 1, first will execute and when 0 second.
                dp[ind][1] = max(-prices[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);
            
                dp[ind][0] = max(prices[ind] + dp[ind + 2][1], 0 + dp[ind + 1][0]);
        }

        return dp[0][1];
    }
};