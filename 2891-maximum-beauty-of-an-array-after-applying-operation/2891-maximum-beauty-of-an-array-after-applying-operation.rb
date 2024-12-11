# @param {Integer[]} nums
# @param {Integer} k
# @return {Integer}
def maximum_beauty(nums, k)
    nums.sort!
    l = 0
    r = 0
    ans = 0

    while r < nums.size
        while nums[r] - nums[l] > 2 * k
            l += 1
        end
        ans = [ans, r - l + 1].max
        r += 1
    end

    ans
end
