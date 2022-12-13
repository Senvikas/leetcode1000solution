class Solution {
public:
    int f(vector<int>& c, int ind, int t, vector<vector<int>>&dp)
    {
        //if(t == 0) return 0;
        if(ind == 0) 
        {
           if(t%c[ind] == 0) return t/c[ind];
            return 1e8;
        }
        if(dp[ind][t] != -1) return dp[ind][t];
        
        int exc = f(c, ind-1, t, dp);
        int inc = 1e8;
        if(c[ind] <= t) inc = 1 + f(c, ind, t-c[ind], dp);
        
        return dp[ind][t] = min(exc, inc);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
      int  ans = f(coins, n-1, amount, dp); return ans == 1e8 ? -1 : ans;
    }
};