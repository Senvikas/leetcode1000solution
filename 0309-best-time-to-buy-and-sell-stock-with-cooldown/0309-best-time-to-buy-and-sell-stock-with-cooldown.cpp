class Solution
{
    public:
        int solveMemo(vector<int> &prices, int day, bool buy, vector<vector< int>> &dp)
        {

            if (day >= prices.size())
            {
                return 0;
            }
            if (dp[day][buy] != -1) return dp[day][buy];

           	// First Choice
            int ans1 = solveMemo(prices, day + 1, buy, dp);	// no transaction this day

           	// Second Choice
            int ans2 = 0;
           	// doing the required transaction this day
            if (buy)
            {
                ans2 = -prices[day] + solveMemo(prices, day + 1, false, dp);
            }
            else
            {
                ans2 = prices[day] + solveMemo(prices, day + 2, true, dp);
            }

            return dp[day][buy] = max(ans1, ans2);
        }
    int solveDP1(vector<int> &prices)
    {

        int dp[prices.size() + 2][2];

        for (int day = (int) prices.size() + 1; day >= 0; day--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {

                int &ans = dp[day][buy];

                if (day >= prices.size())
                {
                    ans = 0;
                }
                else
                {

                   	// First Choice
                    int ans1 = dp[day + 1][buy];	// no transaction this say

                   	// Second Choice
                    int ans2 = 0;	// doing the required transaction this day

                    if (buy)
                    {
                        ans2 = -prices[day] + dp[day + 1][0];
                    }
                    else
                    {
                        ans2 = prices[day] + dp[day + 2][1];
                    }

                    ans = max(ans1, ans2);
                }
            }
        }

        return dp[0][1];
    }

    int maxProfit(vector<int> &prices)
    {
       	// Memoization Solution
        /*  vector<vector < int>> dp(prices.size() + 2, vector < int>(2, -1));
           int ans = solveMemo(prices, 0, true, dp);
           return ans;        */

        return solveDP1(prices);
    }
};