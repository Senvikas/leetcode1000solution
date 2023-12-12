class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        first, sec = nums[0], nums[1]
        if first < sec:
            first, sec = sec, first

        for i in range(2, len(nums)):
            if first < nums[i]:
                sec = first
                first = nums[i]
            elif sec < nums[i]:
                sec = nums[i]

        ans = (first - 1) * (sec - 1)
        return ans