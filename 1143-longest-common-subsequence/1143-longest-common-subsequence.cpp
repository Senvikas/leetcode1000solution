class Solution {
public:
    int spaceOpt2(string &text1, string &text2){
        int m = text1.size(), n = text2.size();
        vector<int> prev(m+1, 0), curr(m+1, 0);
        
        //base case, for ind1 = 0 and ind2 anything -> 0 and vise versa, but already 0
        
        for(int ind1=1; ind1<=m; ind1++){
            for(int ind2=1; ind2<=n; ind2++){
                //if matches
                if(text1[ind1-1] == text2[ind2-1]){  //for shifting added -1
                    curr[ind2] = 1 + prev[ind2-1];
                }
                //else, otherwise
                else curr[ind2] = 0 + max(prev[ind2], prev[ind2-1]);
            }
            prev = curr;
        }
        
        return prev[n];
    }
    
    int spaceOpt(string &text1, string &text2){
        int m = text1.size(), n = text2.size();
        vector<int> prev(n+1, 0), curr(n+1, 0);
        
        //base case, for ind1 = 0 and ind2 anything -> 0 and vise versa, but already 0
        
        for(int ind1=1; ind1<=m; ind1++){
            for(int ind2=1; ind2<=n; ind2++){
                //if matches
                if(text1[ind1-1] == text2[ind2-1]){  //for shifting added -1
                    curr[ind2] = 1 + prev[ind2-1];
                }
                //else, otherwise
                else curr[ind2] = 0 + max(prev[ind2], curr[ind2-1]);
            }
            prev = curr;
        }
        
        return prev[n];
    }
    
    int tabulation(string &text1, string &text2){
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        //base case, for ind1 = 0 and ind2 anything -> 0 and vise versa, but already 0
        
        for(int ind1=1; ind1<=m; ind1++){
            for(int ind2=1; ind2<=n; ind2++){
                //if matches
                if(text1[ind1-1] == text2[ind2-1]){  //for shifting added -1
                    dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                }
                //else, otherwise
                else dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
            }
        }
        
        return dp[m][n];
    }
    
    int solveRec(int ind1, int ind2, string &text1, string &text2, 
                vector<vector<int>> &dp){
        //base case
        // if(ind1 < 0 || ind2 < 0) return 0;
        if(ind1 == 0 || ind2 == 0) return 0;
        
        //already computed
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
        //if matches
        if(text1[ind1-1] == text2[ind2-1]){  //for shifting added -1
            return dp[ind1][ind2] = 1 + solveRec(ind1-1, ind2-1, text1, text2, dp);
        }
        //else, otherwise
        return dp[ind1][ind2] = 0 + max(solveRec(ind1-1, ind2, text1, text2, dp), solveRec(ind1, ind2-1, text1, text2, dp));
        
    }
    
    
    int longestCommonSubsequence(string text1, string text2) {
        int ans = 0;
        
        int m = text1.size(), n = text2.size();
        
        //vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        //ans = solveRec(m, n, text1, text2, dp);
        
        //ans = tabulation(text1, text2);
        
        ans = spaceOpt(text1, text2);
        
        
        
        
        
        return ans;
    }
};