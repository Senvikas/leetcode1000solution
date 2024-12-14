# @param {Integer[]} nums
# @return {Integer}
def continuous_subarrays(nums)
    ans = 0
    l = 0
    freq = Hash.new(0)

    nums.each_with_index do |num, r|
        freq[num] += 1

        maxi = freq.keys.max
        mini = freq.keys.min

        while maxi - mini > 2
            freq[nums[l]] -= 1
            freq.delete(nums[l]) if freq[nums[l]] == 0
            l += 1

            maxi = freq.keys.max
            mini = freq.keys.min
        end

        ans += (r - l + 1)
    end

    ans
end
