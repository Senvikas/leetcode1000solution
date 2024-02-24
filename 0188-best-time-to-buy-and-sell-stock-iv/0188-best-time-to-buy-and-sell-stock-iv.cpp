class Solution
{
    public:
        int f(int ind, int cb, int k, int n, vector<int> &pr, vector<vector< vector< int>>> &dp)
        {
            if (ind >= n) return 0;

            if (dp[ind][cb][k] != -1) return dp[ind][cb][k];

            if (cb)
            {
                return dp[ind][cb][k] = max(-pr[ind] + f(ind + 1, 0, k - 1, n, pr, dp),
                    0 + f(ind + 1, 1, k, n, pr, dp));
            }
            else
            {
                return dp[ind][cb][k] = max(pr[ind] + f(ind + 1, 1, k, n, pr, dp), 0 + f(ind + 1, 0, k, n, pr, dp));
            }
        }

    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector< int>>> dp(n + 1, vector<vector < int>> (2, vector<int> (k + 1, 0)));
       	// return f(0, 1, prices, n, 2, dp);
       	//         for(int i=0; i < 2; i++){
       	//             for(int j=0; j < 3; j++){
       	//                 dp[n][i][j] = 0;
       	//             }
       	//         }  already done.

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int cb = 0; cb < 2; cb++)
            {
                for (int cap = 1; cap < k + 1; cap++)
                {

                    if (cb)
                    {
                        dp[ind][cb][cap] = max(-prices[ind] + dp[ind + 1][0][cap],
                            0 + dp[ind + 1][1][cap]);
                    }
                    else
                    {
                        dp[ind][cb][cap] = max(prices[ind] + dp[ind + 1][1][cap - 1],
                            dp[ind + 1][0][cap]);
                    }
                }
            }
        }

        return dp[0][1][k];
    }
};