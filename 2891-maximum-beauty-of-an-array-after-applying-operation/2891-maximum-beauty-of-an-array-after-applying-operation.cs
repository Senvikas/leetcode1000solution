public class Solution {
    public int MaximumBeauty(int[] nums, int k) {
        Array.Sort(nums);
        int l = 0, r = 0, n = nums.Length, ans = 0;

        while (r < n) {
            while (nums[r] - nums[l] > 2 * k) {
                l++;
            }
            ans = Math.Max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
}
