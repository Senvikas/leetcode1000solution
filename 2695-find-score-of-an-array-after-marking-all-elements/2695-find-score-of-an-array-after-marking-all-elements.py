class Solution:
    def findScore(self, nums: List[int]) -> int:
        n = len(nums)
        score = 0

        val_ind = [(nums[i], i) for i in range(n)]
        val_ind.sort()

        marked = [False] * n

        for val, ind in val_ind:
            if marked[ind]:
                continue

            score += val

            if ind > 0:
                marked[ind - 1] = True
            marked[ind] = True
            if ind < n - 1:
                marked[ind + 1] = True

        return score
