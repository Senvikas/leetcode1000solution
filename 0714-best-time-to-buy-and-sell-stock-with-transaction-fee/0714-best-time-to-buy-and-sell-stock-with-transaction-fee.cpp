class Solution {
public:
    int n;
    int f(int ind, int cb, int fee, vector<int> &pr, vector<vector<int>> &dp){
        if(ind >= n) return 0;
        
        if(dp[ind][cb] != -1) return dp[ind][cb];
        
        if(cb) return dp[ind][cb] = max(-pr[ind] + f(ind+1, 0, fee, pr, dp), 0 + f(ind+1, 1, fee, pr, dp));
        return dp[ind][cb] = max(pr[ind] - fee + f(ind+1, 1, fee, pr, dp), 0 + f(ind+1, 0, fee, pr, dp)); // at selling pay the fee.
    }
    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        //return f(0, 1, fee, prices, dp);
        
        for(int ind=n-1; ind>=0; ind--){
            //for(int cb=0; cb<2; cb++){
                
                dp[ind][1] = max(-prices[ind] + dp[ind+1][0], 0 + dp[ind + 1][1]);
                dp[ind][0] = max(prices[ind] - fee + dp[ind+1][1], 0 + dp[ind+1][0]);
                
            //}
        }
        
        return dp[0][1];
    }
};