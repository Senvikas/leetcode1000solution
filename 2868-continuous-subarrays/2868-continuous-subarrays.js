/**
 * @param {number[]} nums
 * @return {number}
 */
var continuousSubarrays = function(nums) {
    let ans = 0;
    let l = 0;
    const freq = new Map();

    for (let r = 0; r < nums.length; r++) {
        freq.set(nums[r], (freq.get(nums[r]) || 0) + 1);

        let maxi = Math.max(...freq.keys());
        let mini = Math.min(...freq.keys());

        while (maxi - mini > 2) {
            freq.set(nums[l], freq.get(nums[l]) - 1);
            if (freq.get(nums[l]) === 0) {
                freq.delete(nums[l]);
            }
            l++;

            maxi = Math.max(...freq.keys());
            mini = Math.min(...freq.keys());
        }

        ans += (r - l + 1);
    }

    return ans;
};
