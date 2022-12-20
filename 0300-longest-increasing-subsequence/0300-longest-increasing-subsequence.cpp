class Solution
{
    public:

        int f(int ind, int prev_ind, vector<int> &arr, int n, vector<vector< int>> &dp)
        {
            if (ind == n) return 0;
            if (dp[ind][prev_ind + 1] != -1) return dp[ind][prev_ind + 1];
            int len = f(ind + 1, prev_ind, arr, n, dp);
            if (prev_ind == -1 || arr[ind] > arr[prev_ind])
                len = max(len, 1 + f(ind + 1, ind, arr, n, dp));

            return dp[ind][prev_ind + 1] = len;
        }

    int lengthOfLIS(vector<int> &arr)
    {
       	//rules 1.express everything in terms of ind
       	//2. explore all possibilities
       	//3. return maximum
       	//4. basecase
        int n = arr.size();
        /*
        vector<vector < int>> dp(n, vector<int> (n + 1, -1));
        return f(0, -1, arr, n, dp);
        */

        /*   	//memoization
        vector<vector < int>> dp(n + 1, vector<int> (n + 1, 0));
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
            {
                int len = dp[ind + 1][prev_ind + 1];
                if (prev_ind == -1 || arr[ind] > arr[prev_ind])
                    len = max(len, 1 + dp[ind + 1][ind + 1]);

                dp[ind][prev_ind + 1] = len;
            }
        }
        return dp[0][0];

        */

        /*
       	//space optimizatoin
        vector<int> next_row(n + 1, 0), curr_row(n + 1, 0);
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
            {
                int len = next_row[prev_ind + 1];
                if (prev_ind == -1 || arr[ind] > arr[prev_ind])
                    len = max(len, 1 + next_row[ind + 1]);

                curr_row[prev_ind + 1] = len;
            }
            next_row = curr_row;
        }
        return curr_row[0];
        */

       	//intuitve
        vector<int> dp(n, 1);
        int ans = 1;
        for (int ind = 0; ind < n; ind++)
        {
            for (int prev_ind = 0; prev_ind < ind; prev_ind++)
            {
                if (arr[ind] > arr[prev_ind])
                {
                    dp[ind] = max(dp[ind], 1 + dp[prev_ind]);
                }
            }
            ans = max(ans, dp[ind]);
        }
        return ans;
    }
};