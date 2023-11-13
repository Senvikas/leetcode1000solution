class Solution {
    boolean solve(int[] nums, int ind, int target, int[] dp){
        if(ind == target) return true;
        if(ind > target) return false;
        
        if(dp[ind] == 1) return true;
        
        int maxreach = nums[ind];
        boolean fromNewInd = false;
        for(int jump = 1; jump <= maxreach; jump++){
            int newInd = ind + jump;
            fromNewInd = solve(nums, newInd, target, dp);
            if(fromNewInd) {
                dp[newInd] = 1;
                return true;
            }
        }
        dp[ind] = 0;
        return false;
    }
    
    public boolean canJump(int[] nums) {
        int n = nums.length;
        boolean[] dp = new boolean[100001];
        //Arrays.fill(dp, -1);
        //return solve(nums, 0, nums.length-1, dp);
        
        dp[n-1] = true;
        
        for(int i=n-2; i>=0; i--){
            int maxJump = Math.min(i + nums[i], n - 1);
            for(int j=i+1; j<=maxJump; j++){
                if(dp[j]) {dp[i] = true; break;}
            }
        }
        return dp[0];
    }
}