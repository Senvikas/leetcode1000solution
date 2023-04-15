class Solution
{
    int dfs(const std::vector<std::vector < int>> &piles,
        int start, int k, std::vector<std::vector < int>> &slate)
    {
        if ((k < 0) || (start >= piles.size()))
            return 0;
        if (slate[start][k] > 0)
        {
            return slate[start][k];
        }
        int withOutPile = dfs(piles, start + 1, k, slate),
            val = 0, withPile = 0;
        for (int i = 0; i<std::min<int> (piles[start].size(), k); ++i)
        {
            val += piles[start][i];
            withPile = std::max<int> (withPile,
                val + dfs(piles, start + 1, k - i - 1, slate));
        }
        return slate[start][k] = std::max<int> (withPile, withOutPile);
    }
    public:
        int maxValueOfCoins(vector<vector < int>> &piles, int k)
        {
            std::vector<std::vector < int>> dp(piles.size(), std::vector<int> (k + 1, 0));
            return dfs(piles, 0, k, dp);
        }
};