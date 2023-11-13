class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int count0 = 0;
        for(int i : nums){
            if(i==0) count0++;
        }
        if(count0 > 1) return new int[n];
        int multi = 1;
        for(int i : nums){
            if(i != 0)multi *= i;
        }
        int[] ans = new int[n];
        if(count0 == 1){
            for(int i=0; i<n; i++){
            if(nums[i] == 0)ans[i] = multi;
        }
        }
            else{
                for(int i=0; i<n; i++){
                    ans[i] = multi/nums[i]; 
                }
            }
        return ans;
    }
}