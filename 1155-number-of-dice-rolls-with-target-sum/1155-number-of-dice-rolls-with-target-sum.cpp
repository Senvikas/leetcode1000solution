class Solution {
    int mod=1000000000+7;
public:
  int cal(int n,int target,int k,vector<vector<int>>&dp){
            if(n==0 && target!=0)
            return 0;
            if(n==0 && target==0)
            return 1;
            if(dp[n][target]!=-1)
            return dp[n][target];
         int x=0;
      for(int i=1;i<=k;i++){
          if(target>=i){
              x=(x+cal(n-1,target-i,k,dp))%mod;
          }
      }
      return dp[n][target]=x;
  }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return cal(n,target,k,dp)%mod;
    }
};