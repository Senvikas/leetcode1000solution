class Solution {
    public long zeroFilledSubarray(int[] nums) {
        long ans=0;
        long ei=0;
        for(int x:nums){
            if(x==0){
                ei+=1;
                ans+=ei;
            }
            else{
                ei=0;
            }
        }
        return ans;
    }
}