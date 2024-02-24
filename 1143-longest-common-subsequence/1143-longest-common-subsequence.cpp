class Solution {
public:
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
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        ans = solveRec(m, n, text1, text2, dp);
        
        //vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        
        
        
        
        
        
        return ans;
    }
};