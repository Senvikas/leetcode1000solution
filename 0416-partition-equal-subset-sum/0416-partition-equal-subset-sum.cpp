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
        vector<vector < int>> dp(201, vector<int> (t_sum / 2 + 1, -1));
        return solve(arr, t_sum / 2, n - 1, dp);
    }
};