/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maximumBeauty = function(nums, k) {
    nums.sort((a, b) => a - b);
    let l = 0, r = 0, n = nums.length, ans = 0;

    while (r < n) {
        while (nums[r] - nums[l] > 2 * k) {
            l++;
        }
        ans = Math.max(ans, r - l + 1);
        r++;
    }

    return ans;
};
