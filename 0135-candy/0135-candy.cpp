class Solution {
public:
    int candy(std::vector<int> &ratings) {
        const int n = ratings.size();
        int candies[n], ans = n;
        std::fill_n(candies, n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1]) {
                int prev = candies[i];
                candies[i] = candies[i - 1] + 1;
                ans += candies[i] - prev;
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
                int prev = candies[i];
                candies[i] = candies[i + 1] + 1;
                ans += candies[i] - prev;
            }
        }
        return ans;
    }
};