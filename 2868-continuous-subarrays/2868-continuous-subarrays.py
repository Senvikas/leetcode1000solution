class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        ans = 0
        l = 0
        n = len(nums)
        freq = {}

        for r in range(n):
            freq[nums[r]] = freq.get(nums[r], 0) + 1

            maxi = max(freq.keys())
            mini = min(freq.keys())

            while maxi - mini > 2:
                freq[nums[l]] -= 1
                if freq[nums[l]] == 0:
                    del freq[nums[l]]
                l += 1

                maxi = max(freq.keys())
                mini = min(freq.keys())

            ans += (r - l + 1)

        return ans
