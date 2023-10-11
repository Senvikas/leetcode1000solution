class Solution {
public:
    int solve(vector<int> &arr, int am, int ind, vector<vector<int>> &dp){
        //base case 
        if(am == 0) return 0;
        if(ind >= arr.size()) return 1e8;
        
        if(dp[ind][am] != -1) return dp[ind][am];
        int take = 1e8;
        if(am >= arr[ind]) take = 1 + solve(arr, am-arr[ind], ind, dp);
        
        int leave = solve(arr, am, ind+1, dp);
        
        return dp[ind][am] = min(take, leave);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(12, vector<int>(10001, -1));
        int ans = solve(coins, amount, 0, dp);
        if(ans >= 1e8) return -1;
        return ans;
    }
};