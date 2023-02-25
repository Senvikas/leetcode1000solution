class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int min_buy = INT_MAX;
        int profit = INT_MIN;
        for(int i=0; i<arr.size(); i++)
        {
            min_buy = min(min_buy, arr[i]);
            profit  = max(profit, arr[i]-min_buy);
        }if(profit < 0) return 0;
        else return profit;
    }
};