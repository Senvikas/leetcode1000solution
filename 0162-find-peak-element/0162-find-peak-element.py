import time
from typing import List

class Solution:
    def solve(self, nums, start, end):
        while start < end:
            mid = start + (end - start) // 2

            if nums[mid] > nums[mid + 1]:
                return self.solve(nums, start, mid)
            elif nums[mid] < nums[mid + 1]:
                return self.solve(nums, mid + 1, end)

        return start  # or end, since start and end will be equal

    def findPeakElement(self, nums: List[int]) -> int:
        start_time = time.time()
        n = len(nums)
        peak_index = self.solve(nums, 0, n - 1)
        #print(f"Execution Time: {time.time() - start_time} seconds")
        return peak_index
