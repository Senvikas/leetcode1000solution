class Solution {
public:
        bool f(int ind, int t, vector<int> &arr, vector<vector<int>> &dp){
        if(t == 0) return true;
        if(t<0) return false;
        if(ind == 0) return t==arr[0];

        if(dp[ind][t] != -1){
            bool ans = dp[ind][t] == 0 ? false : true;
            return ans;
        }


        bool ans = f(ind-1, t-arr[ind], arr, dp) || f(ind-1, t, arr, dp);
        if(ans == true){
            dp[ind][t] = 1;

        }else{
            dp[ind][t] = 0;

        }
        return ans;
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;
        
        vector<vector<int>> dp(n, vector<int>(sum/2+1, -1));
        return f(n-1, sum/2, nums, dp);
    }
};