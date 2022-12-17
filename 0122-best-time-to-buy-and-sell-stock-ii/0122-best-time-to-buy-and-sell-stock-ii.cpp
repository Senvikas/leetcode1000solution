class Solution
{
    public:
        int f(int ind, int can_buy, int n, vector<int> &p, vector<vector< int>> &dp)
        {
            if (ind == n) return 0;
            if (dp[ind][can_buy] != -1) return dp[ind][can_buy];
            int profit = 0;

            if (can_buy == 1)
            {
                int chooseToBuy = -p[ind] + f(ind + 1, 0, n, p, dp);
                int NotBuying = 0 + f(ind + 1, 1, n, p, dp);

                profit = max(chooseToBuy, NotBuying);
            }
            else
            {
                int chooseToSell = p[ind] + f(ind + 1, 1, n, p, dp);
                int NotSelling = 0 + f(ind + 1, 0, n, p, dp);

                profit = max(chooseToSell, NotSelling);
            }
            return dp[ind][can_buy] = profit;
        }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        /*//genereal approach
       int profit = 0;
       for(int i=1; i < n; i++)
       {
           if(prices[i] > prices[i-1])
           profit += prices[i] - prices[i-1];
       } 

       return profit;           */

       	//Dynamic programming
        /*return f(0, 1, n, prices);    */	//recursive
        /*    vector<vector < int>> dp(n, vector<int> (2, -1));
               return f(0, 1, n, prices, dp);         */	//memoization

       	//Tabulation
        vector<vector < int>> dp(n + 1, vector<int> (2, 0));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int c = 0; c < 2; c++)
            {
                int profit = 0;
                if (c == 1)
                {
                    int chooseToBuy = -prices[ind] + dp[ind + 1][0];
                    int NotBuying = 0 + dp[ind + 1][1];

                    profit = max(chooseToBuy, NotBuying);
                }
                else
                {
                    int chooseToSell = prices[ind] + dp[ind + 1][1];
                    int NotSelling = 0 + dp[ind + 1][0];

                    profit = max(chooseToSell, NotSelling);
                }
                dp[ind][c] = profit;
            }
        }
        return dp[0][1];
    }
};