class Solution
{
    public:

       	//WILL GIVE TLE
        int solve_recursively(vector<vector < int>> &arr, int i, int j, int n)
        {
           	//base case 
            if (i >= n) return 0;
            int d = arr[i][j] + solve_recursively(arr, i + 1, j, n);
            int dg = arr[i][j] + solve_recursively(arr, i + 1, j + 1, n);
            return min(d, dg);
        }

    int solve_mem(vector<vector < int>> &arr, int i, int j, int n, vector< vector< int>> &dp)
    {
       	//base case 
        if (i >= n) return 0;

        if (dp[i][j] != -1) return dp[i][j];
        int d = arr[i][j] + solve_mem(arr, i + 1, j, n, dp);
        int dg = arr[i][j] + solve_mem(arr, i + 1, j + 1, n, dp);
        return dp[i][j] = min(d, dg);
    }
    int minimumTotal(vector<vector < int>> &triangle)
    {
        int n = triangle.size();
       	//return solve_recursively(triangle,0, 0, n);

       	//memoization
        vector<vector < int>> dp(n, vector<int> (n, -1));
        return solve_mem(triangle, 0, 0, n, dp);
    }
};