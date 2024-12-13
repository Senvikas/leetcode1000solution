/**
 * @param {number[]} nums
 * @return {number}
 */
var findScore = function(nums) {
    const n = nums.length;
    let score = 0;

    // Create value-index pairs
    const valInd = nums.map((val, ind) => [val, ind]);

    // Sort by value, then index
    valInd.sort((a, b) => a[0] === b[0] ? a[1] - b[1] : a[0] - b[0]);

    const marked = Array(n).fill(false);

    for (const [val, ind] of valInd) {
        if (marked[ind]) continue;

        score += val;

        if (ind > 0) marked[ind - 1] = true;
        marked[ind] = true;
        if (ind < n - 1) marked[ind + 1] = true;
    }

    return score;
};
