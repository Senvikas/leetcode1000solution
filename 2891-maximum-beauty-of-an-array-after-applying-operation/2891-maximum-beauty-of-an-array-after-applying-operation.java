class Solution {
    public int maximumBeauty(int[] nums, int k) {
        Arrays.sort(nums);
        int l = 0, r = 0, n = nums.length, ans = 0;

        while (r < n) {
            while (nums[r] - nums[l] > 2 * k) {
                l++;
            }
            ans = Math.max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
}
