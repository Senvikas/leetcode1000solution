class Solution {
public:
    int f(int i, int j, string& s, string& t, vector<vector<int>> &dp){
        //base case  with ind shifting.
        if(i==0 ){
            return j;
        }
        if(j==0) {
            return i;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        
        if(s[i-1] == t[j-1]) return f(i-1, j-1, s, t, dp);
        int del = 0, ins = 0, rep = 0;
        del = 1 + f(i-1, j, s, t, dp);
        ins = 1 + f(i, j-1, s, t, dp);
        rep = 1 + f(i-1, j-1, s, t, dp);
        
        
        return dp[i][j] = min(del, min(ins, rep));
        
        
    }
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        /*
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return f(m, n, word1, word2, dp);
        */
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        //base case
        for(int j=0; j<=n; j++) dp[0][j] = j;
        for(int i=0; i<=m; i++) dp[i][0] = i;
        
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){

                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                
                else{
                    int del = 1 + dp[i-1][j];
                    int ins = 1 + dp[i][j-1];
                    int rep = 1 + dp[i-1][j-1];
                    
                    dp[i][j] = min(del, min(ins, rep));
                }
            
            }
        }
        
        return dp[m][n];
    }
};