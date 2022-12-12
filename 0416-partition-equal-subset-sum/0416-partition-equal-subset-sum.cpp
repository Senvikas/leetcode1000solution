class Solution
{
    public:
        bool solve(vector<int> &arr, int s, int ind, vector<vector< int>> &dp)
        {
           	//base cases

            if (s == 0) return 1;
            if (ind == 0) return arr[0] == s;
            if (dp[ind][s] != -1) return dp[ind][s];
            bool exc = solve(arr, s, ind - 1, dp);
            bool inc = false;
            if (s >= arr[ind]) inc = solve(arr, s - arr[ind], ind - 1, dp);

            return dp[ind][s] = exc | inc;
        }

    bool canPartition(vector<int> &arr)
    {
        int t_sum = 0;
        int n = arr.size();
        for (auto &x: arr) t_sum += x;
        cout << t_sum << endl;
        if (t_sum & 1) return false;
        int k = t_sum / 2 + 1;
        /*    vector<vector < int>> dp(201, vector < int>(k,-1));
               return solve(arr, k-1, n - 1, dp);            */

        /*     vector<vector < bool>> dp(201, vector<bool> (k, 0));
               for (int i = 0; i < n; i++) dp[i][0] = true;
               if (arr[0] <= k) dp[0][arr[0]] = true;

               for (int ind = 1; ind < n; ind++)
               {
                   for (int tar = 1; tar < k; tar++)
                   {
                       bool exc = dp[ind - 1][tar];
                       bool inc = false;
                       if (tar >= arr[ind]) inc = dp[ind - 1][tar - arr[ind]];

                      	//update the dp
                       dp[ind][tar] = exc || inc;
                   }
               }
               return dp[n - 1][k - 1];           */

       	//further space optimization
        vector<bool> prev(k, false), curr(k, false);
        prev[0] = true;
        if (arr[0] < k) prev[arr[0]] = true;
        for (int ind = 1; ind < n; ind++)
        {
            for (int tar = 1; tar < k; tar++)
                curr[tar] = prev[tar] | ((tar >= arr[ind]) ? prev[tar - arr[ind]] : false);
            prev = curr;
        }
        return prev[k - 1];
    }
};