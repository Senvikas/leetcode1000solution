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

    int lengthOfLIS(vector<int> &nums)
    {
       	//rules 1.express everything in terms of ind
       	//2. explore all possibilities
       	//3. return maximum
       	//4. basecase
        int n = nums.size();
        vector<vector < int>> dp(n, vector<int> (n + 1, -1));
        return f(0, -1, nums, n, dp);
    }
};