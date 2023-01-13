class Solution {
public:
    // function to calculate the probability that the nth person gets the nth seat
    double nthPersonGetsNthSeat(int n) {
        // if there is only one person, the probability is 1
        if(n == 1) return 1;
        // vector to store the probability of getting the nth seat
        vector<double> dp(2, 0); 
        // initial probability of getting the first seat
        dp[0] = 1.0/n;
        // iterate from 3rd person to nth person
        for(int i = 3; i <= n; ++i)
        {
            // update the probability of getting the nth seat
            dp[0] = dp[1] = dp[0] + dp[0]/(n-i+2);
        }
        // return the probability of not getting the nth seat
        return 1 - dp[0];
    }
};
