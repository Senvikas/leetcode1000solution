class Solution {
    public int maxSubArray(int[] nums) {
        int ans = Integer.MIN_VALUE, currsum = 0;
        for(int i : nums){
            currsum += i;
            ans = Math.max(ans, currsum);
            if(currsum < 0) currsum = 0;
        }
        
        return ans;
    }
}