/**
 * @param {number[]} nums
 * @param {number[][]} queries
 * @return {boolean[]}
 */
var isArraySpecial = function(nums, queries) {
    const n = nums.length;
    const index = [];
    let prev = nums[0] % 2 === 1;

    for (let i = 1; i < n; i++) {
        const curr = nums[i] % 2 === 1;
        if (prev === curr) {
            index.push(i - 1);
        }
        prev = curr;
    }

    const result = [];
    for (const [from, to] of queries) {
        let left = 0, right = index.length - 1, found = -1;
        while (left <= right) {
            const mid = Math.floor((left + right) / 2);
            if (index[mid] >= from) {
                found = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        result.push(found === -1 || to <= index[found]);
    }

    return result;
};
