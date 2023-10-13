class Solution {
public: 
// question is asking us to reach the nth index by refering it as the top
    int solve(int src, vector<int>& cost,vector<int>& dp){

        if(src == cost.size())return 0;      // when we reach the top no cost is needed

        if(src==cost.size()+1){             // just using a greater value than given in the constraints
            return 1001;
        }

        if(dp[src]!=-1)return dp[src];
        int oneStep = cost[src] + solve(src+1,cost,dp);  // one step jump
        int twoStep = cost[src] + solve(src+2,cost,dp);  // two step jump

        return dp[src] = min(oneStep, twoStep);          // minimum of both
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        // DP approach 
        vector<int> dp(n+1,-1);   // since the values goes from 0 to n :: n+1
        int zero_ind= solve(0,cost,dp);   // start from 0th index
        int first_ind=1001;
       // if(n>1){           // if cost.length would have been less than 2
            first_ind = solve(1,cost,dp);  // start from 1st index
       // }
        return min(zero_ind,first_ind);   //min of both
    }
};