class Solution {
public:
    int getMaxProfit(vector<int> &stocks){  
    int minBuy = 1e9, maxProfit = 0;

    for(int i=0; i<stocks.size(); i++) // Time Comp: O(n) and SC O(1)
    {
        // selling at curr day
        maxProfit = max(maxProfit, stocks[i] - minBuy);

        // update min, for future
        minBuy = min(minBuy, stocks[i]);
    }

    return maxProfit;
}

    int maxProfit(vector<int>& prices) {
        return getMaxProfit(prices);
    }
};