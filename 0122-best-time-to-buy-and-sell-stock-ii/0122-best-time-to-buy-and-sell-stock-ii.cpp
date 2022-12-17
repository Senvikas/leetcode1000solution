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
        /* return f(0, 1, n, prices);    */	//recursive
        vector<vector < int>> dp(n + 1, vector<int> (2, -1));
        return f(0, 1, n, prices, dp);
    }
};