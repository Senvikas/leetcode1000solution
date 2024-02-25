class Solution {
public:
    int n;
    int f(int ind, int prev, vector<int> &nums, vector<vector<int>> &dp){
        //base case
        if(ind > n) return 0;
        
        //already visited
        if(dp[ind][prev] != -1) return dp[ind][prev];
        
        //1 .pick
        int pick = 0;
        if(prev == 0 || nums[prev-1] < nums[ind-1]) {
            int chooseToPick = 1 + f(ind+1, ind, nums, dp);
            int chooseNotToPick = 0 + f(ind+1, prev, nums, dp);
            pick = max(chooseToPick, chooseNotToPick);
        }
        
        int notPick = f(ind+1, prev, nums, dp);
                                                            
        return dp[ind][prev]  =  max(pick, notPick);
                                                            
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return f(1, 0, nums, dp);  //shifte from 0 -1 to 1 0
    }
};