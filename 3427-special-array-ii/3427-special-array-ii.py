class Solution:
    def isArraySpecial(self, nums: List[int], queries: List[List[int]]) -> List[bool]:
        index = []
        n = len(nums)

        # Preprocess to find indices where parity is the same for adjacent elements
        prev = nums[0] % 2  # Check if the first element is odd
        for i in range(1, n):
            curr = nums[i] % 2  # Check if the current element is odd
            if prev == curr:    # Parity is the same
                index.append(i - 1)
            prev = curr

        # Process each query
        ans = []
        for query in queries:
            from_idx, to_idx = query

            # Binary search to find the first index >= from_idx
            idx = bisect_left(index, from_idx)
            if idx == len(index) or to_idx <= index[idx]:
                ans.append(True)  # No splits in the range
            else:
                ans.append(False)  # Split found in the range

        return ans
