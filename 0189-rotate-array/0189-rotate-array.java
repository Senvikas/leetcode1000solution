class Solution {
    public void reverse(int[] nums, int i, int j){
        while(i<j){
            int a = nums[i];
            nums[i] = nums[j];
            nums[j] = a;
            i++; j--;
        }
        return ;
    }
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        k = k%n; if(k==0) return;
        reverse(nums, 0, n-k-1);
        reverse(nums, n-k, n-1);
        reverse(nums, 0, n-1);
        return ;
    }
}