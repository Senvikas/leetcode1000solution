int m, n;
vector<vector<int>> dp;
class Solution {
public:
    int solve(vector<vector<int>> &og, int i, int j){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        
        if(og[i][j] == 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = solve(og, i-1, j) + solve(og, i, j-1);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        m = og.size();
        n = og[0].size();
        if(og[0][0] == 1 || og[m-1][n-1] == 1) return 0;
        
        // dp = vector<vector<int>>(m, vector<int>(n, -1));
        // return solve(og, m-1, n-1);
        
        /*
        dp = vector<vector<int>>(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(og[i][j] == 1) continue;
                
                if(i>0) dp[i][j] += dp[i-1][j];
                if(j>0) dp[i][j] += dp[i][j-1];
            }
        }
        */
        
        vector<int> prev(n, 0);
        for(int i=0; i<n; i++){
            if(og[0][i] == 0) prev[i] = 1;
            else break;
        }
        
        for(int i=1; i<m; i++){
            vector<int> temp(n, 0);
            for(int j=0; j<n; j++){
                if(og[i][j] == 1) continue;
                else if(j == 0) temp[j] = prev[j];
                else temp[j] = temp[j-1] + prev[j];
            }
            prev = temp;
        }
        
        return prev[n-1];
    }
};