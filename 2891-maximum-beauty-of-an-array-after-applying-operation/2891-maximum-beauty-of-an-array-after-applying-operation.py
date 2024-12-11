class Solution:
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        nums.sort()
        l = r = 0
        n = len(nums)
        ans = 0

        while r < n:
            while nums[r] - nums[l] > 2 * k:
                l += 1
            ans = max(ans, r - l + 1)
            r += 1

        return ans
