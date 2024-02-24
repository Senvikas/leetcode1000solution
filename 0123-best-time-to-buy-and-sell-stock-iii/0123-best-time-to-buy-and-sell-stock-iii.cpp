class Solution {
public:
    int f(int ind, int cb, vector<int> &pr, int n, int cap, vector<vector<vector<int>>> &dp){
        //base case
        if(ind >= n) return 0;
        
        if(dp[ind][cb][cap] != -1) return dp[ind][cb][cap];
        
        int buy = 0, sell = 0;
        if(cb){
            int b = 0;
                if(cap) b = -pr[ind] + f(ind+1, 0, pr, n, cap-1, dp);
                     int nb = 0 + f(ind+1, 1, pr, n, cap, dp);
            
            buy = max(b, nb);
            
        }else{
            int sel = pr[ind] + f(ind+1, 1, pr, n, cap, dp);
            int notSell = f(ind+1, 0, pr, n, cap, dp);
            sell = max(sel, notSell);
        }
        
        return dp[ind][cb][cap] = max(buy, sell);
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        //return f(0, 1, prices, n, 2, dp);
//         for(int i=0; i<2; i++){
//             for(int j=0; j<3; j++){
//                 dp[n][i][j] = 0;    
//             }
//         }  already done.
        
        
        for(int ind=n-1; ind>=0; ind--){
            for(int cb=0; cb<2; cb++){
                for(int cap=1; cap<3; cap++){
                    
                    
                    if(cb){
                        dp[ind][cb][cap] = max(-prices[ind] + dp[ind+1][0][cap],
                                               0 + dp[ind+1][1][cap]);


                    }else{
                        dp[ind][cb][cap] = max(prices[ind] + dp[ind+1][1][cap-1],
                                               dp[ind+1][0][cap]);
                        
                    }
                    
                    
                }
            }
        }
        
        return  dp[0][1][2];
    }
};