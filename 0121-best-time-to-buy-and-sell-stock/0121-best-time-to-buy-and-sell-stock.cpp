class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = prices[0];
        int profit = INT_MIN;
        
        for(int i=1; i<prices.size(); i++){
            profit = max(profit, prices[i] - minBuy);
            minBuy = min(minBuy, prices[i]);
        }
        if(profit < 0) return 0;
        return profit;
    }
};