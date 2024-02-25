class Solution {
public:
    int n;
    int f(int ind, int cb, vector<int> &pr, vector<vector<int>> &dp){
        if(ind >= n) return 0;
        
        if(dp[ind][cb] != -1) return dp[ind][cb];
        if(cb) return dp[ind][cb] = max(-pr[ind] + f(ind+1, 0, pr, dp), 0 + f(ind+1, 1, pr, dp));
        return dp[ind][cb] = max(pr[ind] + f(ind+2, 1, pr, dp), 0 + f(ind+1, 0, pr, dp));
    }
    
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return f(0, 1, prices, dp);
    }
};