class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> dp(n, 1), count(n, 1);
        int longest = 1, indLongest = 0;

        for (int ind = 0; ind < n; ind++)
        {
            for (int prev = 0; prev < ind; prev++)
            {
                if (nums[prev] < nums[ind] && 1 + dp[prev] > dp[ind])
                {
                    dp[ind] = 1 + dp[prev];
                    count[ind] = count[prev];
                }
                else if (nums[prev] < nums[ind] && 1 + dp[prev] == dp[ind])
                {
                    dp[ind] = 1 + dp[prev]; // not needed though, already happening.
                    count[ind] += count[prev];
                }

                if (dp[ind] > longest)
                {
                    longest = dp[ind];
                    indLongest = ind;
                }
            }
        }

        int numberOfLIS = 0;
        for(int ind=0; ind<n; ind++){
            if(dp[ind] == longest) numberOfLIS += count[ind];
        }

        return numberOfLIS;
    }
};


