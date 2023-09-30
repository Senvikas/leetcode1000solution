class Solution {
public:
    int N;
    vector<int> dp;
    int solve(int steps, int n){
        if(steps == n) return 1;
        if(steps > n) return 0;
        if(dp[steps] != -1) return dp[steps];
        int taken1step = solve(steps+1, n);
        int taken2steps = solve(steps+2, n);
        
        return dp[steps] = taken1step + taken2steps;
    }
    int climbStairs(int n) {
        N = n;
        dp = vector<int>(N+1, -1);
        //return solve(0, n);
        
        // dp[0] = 0;
        // dp[1] = 1;
        // dp[2] = 2;
        // for(int i=3; i<=n; i++) dp[i] = dp[i-1]+dp[i-2];
        // return dp[N];
        
        if(n <= 1) return n;
        int prev = 2;
        int prev2 = 1;
        for(int i=3; i<=n; i++) {
            int curr = prev2 + prev;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};