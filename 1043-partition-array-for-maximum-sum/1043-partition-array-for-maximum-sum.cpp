class Solution {
public:
    int f(int i, int k, int n, vector<int> &arr, vector<int> &dp){
        if(i >= n) return 0;
        
        if(dp[i] != -1) return dp[i];
        int maxi = INT_MIN, sum = 0, ans = INT_MIN, len = 0;
        for(int j=i; j<min(n, i+k); j++){
            len++;
            maxi = max(maxi, arr[j]);
            
            sum = maxi * len + f(j+1, k, n, arr, dp);
            
            ans = max(ans, sum);
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);
        //return f(0, k, n, arr, dp);
        
        for(int i=n-1; i>=0; i--){
            int maxi = INT_MIN, sum = 0, ans = INT_MIN, len = 0;
            
            for(int j=i; j<min(n, i+k); j++){
                len++;
                maxi = max(maxi, arr[j]);

                sum = maxi * len + dp[j+1];

                ans = max(ans, sum);
            }
            
            dp[i] = ans;
        }
        
        return dp[0];
    }
};