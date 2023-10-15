/* Will exceed memory limit

#define threeD vector<vector<vector<long long>>>
int mod = 1e9+7;

class Solution {
public:
    int totSteps;
    int solve(int ind, int steps, int len, int stay, int left, int right, threeD &dp){
        if(ind < 0 || ind >= len) return 0;
        if(steps < 0) return 0;
        if(steps == 0){
            if(left > totSteps || right > totSteps ||  left != right) return 0;
            if(left + right + stay != totSteps) return 0;
            return 1;
        }
        
        if(dp[stay][left][right] != -1) return dp[stay][left][right];
        
        long long  s = solve(ind, steps-1, len, stay+1, left, right, dp);
        long long l = solve(ind-1, steps-1, len, stay, left+1, right, dp);
        long long r = solve(ind+1, steps-1, len, stay, left, right+1, dp);
        
        return dp[stay][left][right] =  (s%mod + l%mod + r%mod)%mod;
    }
    
    int numWays(int steps, int arrLen) {
        totSteps = steps;
        threeD dp(500+1, vector<vector<long long>>(500+1, vector<long long>(500+1, -1)));
        long long ans = solve(0, steps, arrLen, 0, 0, 0, dp);
        return (int)ans%mod;
    }
};


*/

int mod = 1e9+7;
#define MOD 1000000007

class Solution {
public:
    int maxReach;
    
    long long solve(int ind, int steps, vector<vector<int>> &dp){
        if(steps < 0 || ind < 0) return 0;
        
        if(steps == 0){
            if(ind == 0) return 1;
            return 0;
        }
        if(ind < 0 || ind >= maxReach) return 0;
        
        if(dp[ind][steps] != -1) return dp[ind][steps];
        
        long long ways = 0;
        
        ways = (ways + solve(ind, steps-1, dp)) % MOD;  // stay

        if (ind > 0)   // can move left
        {
            ways = (ways + solve(ind - 1, steps - 1, dp)) % MOD;
        }

        if (ind < maxReach - 1)   // can move right
        {
            ways = (ways + solve(ind + 1, steps - 1, dp)) % MOD;
        }
        
        return dp[ind][steps] = ways;
    }
    
    int numWays(int steps, int arrLen) {
        maxReach = min(arrLen, steps / 2 + 1);
        vector<vector<int>> dp(maxReach + 1, vector<int>(steps + 1, -1));
        long long ans = solve(0, steps, dp);
        return int(ans % MOD);
    }
};
