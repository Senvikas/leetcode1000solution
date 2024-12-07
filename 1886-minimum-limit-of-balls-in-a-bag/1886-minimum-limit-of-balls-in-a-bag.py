class Solution:
    def tryBreaking(self, nums, mxBalls, tries):
        for num in nums:
            if num < mxBalls:
                continue

            if (num // (tries + 1)) <= mxBalls:
                used = (num // mxBalls) - (1 if num % mxBalls == 0 else 0)
                tries -= used

                if tries < 0:
                    return False
            else:
                return False

        return True

    def minimumSize(self, nums, maxOperations):
        low, high = 1, max(nums)
        ans = high

        while low <= high:
            mid = low + (high - low) // 2

            if self.tryBreaking(nums, mid, maxOperations):
                ans = mid
                high = mid - 1
            else:
                low = mid + 1

        return ans
