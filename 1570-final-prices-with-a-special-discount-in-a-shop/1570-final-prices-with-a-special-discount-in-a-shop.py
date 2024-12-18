class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        n = len(prices)
        ans = prices[:]
        stack = []

        for i in range(n):
            while stack and prices[stack[-1]] >= prices[i]:
                ans[stack.pop()] -= prices[i]
            stack.append(i)

        return ans
