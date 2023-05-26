class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = int(piles.size());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = n - 1, sum = 0; i >= 0; --i) {
            sum += piles[i];
            for (int m = 1; m <= n; ++m) { // the current value of M
                for (int x = 1; x <= min(n, 2 * m); ++x) { // the chosen value of X
                    dp[i][m] = max(dp[i][m], sum - dp[min(i + x, n)][max(m, x)]);
                }
            }
        }
        return dp[0][1];
    }
};