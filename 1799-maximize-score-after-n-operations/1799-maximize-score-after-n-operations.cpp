class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size() / 2;
        vector<int> dp(1 << (2*n));
        
        for (int mask = 1; mask < (1 << (2*n)); mask++) {
            if (__builtin_popcount(mask) % 2 == 1) continue;
            
            int i = __builtin_popcount(mask) / 2;
            for (int x = 0; x < 2*n; x++) {
                if ((mask & (1 << x)) == 0) continue;
                for (int y = x+1; y < 2*n; y++) {
                    if ((mask & (1 << y)) == 0) continue;
                    
                    int score = i * gcd(nums[x], nums[y]);
                    int new_mask = mask ^ (1 << x) ^ (1 << y);
                    dp[mask] = max(dp[mask], dp[new_mask] + score);
                }
            }
        }
        
        return dp[(1 << (2*n)) - 1];
    }
    
private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
