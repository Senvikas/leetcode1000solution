class Solution {
public:
    int f(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        if(i>j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int maxi = INT_MIN;
        for(int ind=i; ind<=j; ind++){
            //burst this ballon out
            int burst = nums[i-1]*nums[ind]*nums[j+1];
            int left = f(i, ind-1, nums, dp);
            int right = f(ind+1, j, nums, dp);
            
            int totalCost = burst + left + right;
            
            maxi = max(maxi, totalCost);
        }
        
        return dp[i][j] = maxi;
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);  // if ind goes out.
        
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        
        for(int i=n; i>=1; i--){
            for(int j=1; j<=n; j++){
                if(i>j) continue;
                
                int maxi = INT_MIN;
                for(int ind=i; ind<=j; ind++){
                    int burst = nums[i-1]*nums[ind]*nums[j+1];
                    int left = dp[i][ind-1];
                    int right = dp[ind+1][j];
                    
                    maxi = max(maxi, burst+left+right);
                }
                
                dp[i][j] = maxi;
            }
        }
        
        return dp[1][n];
        return f(1, n, nums, dp);
    }
};