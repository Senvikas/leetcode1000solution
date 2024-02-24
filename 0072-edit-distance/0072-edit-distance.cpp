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
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return f(m, n, word1, word2, dp);
    }
};