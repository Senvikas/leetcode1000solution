class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, 0));
        
        for(int i=0; i<=amount; i++)
        {
            dp[0][i] = (i%coins[0] == 0);
        }
        
       for(int i=1; i<n; i++)
       {
           for(int a=0; a<=amount; a++)
           {
               int exc = dp[i-1][a];
               int inc = 0;
               if(a >= coins[i]) inc = dp[i][a-coins[i]];
               
               //update
               dp[i][a] = exc + inc;
           }
       }
        
        
        
        return dp[n-1][amount];
    }
};