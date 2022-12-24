class Solution
{
    public:
        int numTilings(int n)
        {
            int mod = 1e9 + 7;
            vector<int> ans(1001);
            ans[0] = 0;
            ans[1] = 1;
            ans[2] = 2;
            ans[3] = 5;
            if (n < 4) return ans[n];
            for (int i = 4; i <= n; i++)
                ans[i] = (2 *ans[i - 1] % mod + ans[i - 3] % mod) % mod;

            return ans[n];
        }
};