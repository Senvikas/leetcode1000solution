class Solution
{
    int dp[1001];
    int solve(vector<int> &arr, int k, int size)
    {
        int cnt = 0;
       	//base case

        if (k < 0)
            return 0;
        
        if (dp[k] != -1)
            return dp[k];
        
        if (k == 0)
            cnt++;

        for (int i = 0; i < size; i++)
            cnt += solve(arr, k - arr[i], size);

        dp[k] = cnt;
        return dp[k];
    }

    public:
        int combinationSum4(vector<int> &nums, int target)
        {
            memset(dp, -1, sizeof(dp));
            int cnt = 0;
            int size = nums.size();
            cnt = solve(nums, target, size);
            return cnt;
        }
};