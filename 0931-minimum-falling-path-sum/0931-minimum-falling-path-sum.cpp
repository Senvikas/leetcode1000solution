class Solution
{
    public:
        int solve(vector<vector < int>> &arr, int n, int i, int j, vector< vector< int>> &dp)
        {
            if (j < 0 || j >= n) return 1e8;
            if (i == n - 1) return arr[i][j];
            if (dp[i][j] != -1) return dp[i][j];
            int d = arr[i][j] + solve(arr, n, i + 1, j, dp);
            int dl = arr[i][j] + solve(arr, n, i + 1, j - 1, dp);
            int dr = arr[i][j] + solve(arr, n, i + 1, j + 1, dp);

            return dp[i][j] = min(d, min(dl, dr));
        }

    int minFallingPathSum(vector<vector < int>> &arr)
    {
        int n = arr[0].size();
        /*vector<vector < int>> dp(n, vector < int>(n, -1));
            int ans = INT_MAX;
            for(int j=0; j < n; j++)
            {
                ans = min(ans, solve(arr, n, 0, j, dp));
            }
            return ans;         */

        /*   	//top -> down
               vector<vector < int>> dp(n, vector<int> (n, 0));
              	//filling up the first row
               for (int j = 0; j < n; j++)
                   dp[0][j] = arr[0][j];

               for (int i = 1; i < n; i++)
               {
                   for (int j = 0; j < n; j++)
                   {
                       int d = arr[i][j] + dp[i - 1][j];
                       int dl = arr[i][j] + (j - 1 >= 0 ? dp[i - 1][j - 1] : 1e6);
                       int dr = arr[i][j] + (j + 1 <= n - 1 ? dp[i - 1][j + 1] : 1e6);

                       dp[i][j] = min(d, min(dl, dr));
                   }
               }

               return* min_element(dp[n - 1].begin(), dp[n - 1].end());        */

       	//space optimization
        vector<int> prev(n, 0), curr(n, 0);
       	//filling up the prev row
        for (int j = 0; j < n; j++)
            prev[j] = arr[0][j];

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                int d = arr[i][j] + prev[j];
                int dl = arr[i][j] + (j - 1 >= 0 ? prev[j - 1] : 1e6);
                int dr = arr[i][j] + (j + 1 <= n - 1 ? prev[j + 1] : 1e6);

                curr[j] = min(d, min(dl, dr));
            }
            prev = curr;
        }
        return* min_element(prev.begin(), prev.end());
    }
};