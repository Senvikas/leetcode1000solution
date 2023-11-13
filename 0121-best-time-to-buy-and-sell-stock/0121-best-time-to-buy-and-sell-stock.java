class Solution {
    public int maxProfit(int[] prices) {
      int profit = 0;
      int mxprofit = 0;
      int currVal = prices[0];
      for(int i=1; i<prices.length; i++){
          profit = prices[i] - currVal;
          mxprofit = Math.max(profit, mxprofit);
          currVal = Math.min(currVal, prices[i]);
      }  
      return mxprofit;
    }
}