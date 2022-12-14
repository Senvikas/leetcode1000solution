class Solution
{
    public:
        int solve(int ind, vector<int> &arr, vector<int> &dp)
        {
            if (ind == 0) return arr[ind];
            if (ind < 0) return 0;
            if (dp[ind] != -1) return dp[ind];
            int exc = solve(ind - 1, arr, dp);
            int inc = arr[ind] + solve(ind - 2, arr, dp);

            return dp[ind] = max(inc, exc);
        }

    int rob(vector<int> &arr)
    {
        int n = arr.size();
       	//if (n == 2) return max(arr[0], arr[1]);
        /*     vector<int> dp(n + 1, -1);
                return solve(n - 1, arr, dp);              */

       	//tabulation
        vector<int> dp(n, 0);
        dp[0] = arr[0];
        if (n > 1)
            dp[1] = max(arr[0], arr[1]);
        for (int ind = 2; ind < n; ind++)
        {
            int exc = dp[ind - 1];
            int inc = arr[ind] + dp[ind - 2];
            dp[ind] = max(exc, inc);
        }
        return dp[n - 1];
    }
};