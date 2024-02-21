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
    


    int tableFillingApp(int n, vector<int> &coins, int amount) {
    // Initialize the dp array with a larger value
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, amount + 1));

    // Base case for amount = 0, no coins are needed
    for (int i = 0; i <= n; i++) 
        dp[i][0] = 0;

    // Filling in DP table
    for (int ind = 1; ind <= n; ind++) {
        for (int am = 1; am <= amount; am++) {
            int notPick = dp[ind - 1][am];

            int pick = amount + 1; // Initialize pick with a larger value
            if (am >= coins[ind - 1]) 
                pick = 1 + dp[ind][am - coins[ind - 1]]; // Corrected the index here

            dp[ind][am] = min(pick, notPick);
        }
    }

    return dp[n][amount] > amount ? -1 : dp[n][amount]; // Return -1 if amount is not achievable
}
    
    int coinChange(vector<int>& coins, int amount) {
        //vector<vector<int>> dp(coins.size(), vector<int>(amount+1, 1e8));
        // int ans = solve(coins, amount, 0, dp);
        // if(ans >= 1e8) return -1;
        // return ans;
        
        int n = coins.size();
        
        return tableFillingApp(n, coins, amount);
        
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INT_MAX - 1));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0; // Base case: no coins are needed to make change for amount 0.
        }

        for (int i = 1; i <= n; i++) {
            for (int am = 1; am <= amount; am++) {
                int take = (am >= coins[i - 1]) ? 1 + dp[i][am - coins[i - 1]] : INT_MAX - 1;
                int leave = dp[i - 1][am];
                dp[i][am] = min(take, leave);
            }
        }

        return (dp[n][amount] == INT_MAX - 1) ? -1 : dp[n][amount];
    }
};