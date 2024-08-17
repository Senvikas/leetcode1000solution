class Solution {
public:
    int mod = 1e9+7;
    int numDistinct(string s, string t) {
        int n1 = s.size(); int n2 =t.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for(int i=0; i<=n1; i++) dp[i][0] = 1;
        
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = (dp[i-1][j-1]%mod + dp[i-1][j]%mod)%mod;
                }else 
                    dp[i][j] = dp[i-1][j]%mod;
            }
        }
        return dp[n1][n2];
    }
};