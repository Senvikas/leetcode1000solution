class Solution {
public:
    int HouseRobberI(vector<int> &arr)
    {
        int n = arr.size();
       	//if (n == 2) return max(arr[0], arr[1]);
        /*     vector<int> dp(n + 1, -1);
                return solve(n - 1, arr, dp);              */

       	//tabulation
        vector<int> dp(n, 0);
        dp[0] = arr[0];
        if (n > 1)
            dp[1] = max(arr[0], arr[1]);
        for (int ind = 2; ind < n; ind++)
        {
            int exc = dp[ind - 1];
            int inc = arr[ind] + dp[ind - 2];
            dp[ind] = max(exc, inc);
        }
        return dp[n - 1];
    }
    
    int rob(vector<int>& nums) {
        vector<int> arr1, arr2;
        int n = nums.size();
        if(n==1) return nums[0];
        for(int i=0; i<n; i++){
            if(i!=0) arr1.push_back(nums[i]);
            if(i!=n-1) arr2.push_back(nums[i]);
        }
        
        return max(HouseRobberI(arr1), HouseRobberI(arr2));
    }
};