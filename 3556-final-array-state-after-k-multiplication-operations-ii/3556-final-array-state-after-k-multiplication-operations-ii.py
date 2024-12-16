class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        MOD = int(1e9 + 7)

        def power(base: int, exp: int) -> int:
            result = 1
            while exp > 0:
                if exp % 2 == 1:
                    result = (result * base) % MOD
                base = (base * base) % MOD
                exp //= 2
            return result

        if multiplier == 1:
            return nums

        # Min-heap to manage the smallest values
        pq = []
        maxi = float("-inf")

        for i, num in enumerate(nums):
            heapq.heappush(pq, (num, i))
            maxi = max(maxi, num)

        # Perform operations until min(nums) * multiplier > max(nums)
        while k > 0:
            val, ind = heapq.heappop(pq)

            if val * multiplier > maxi:
                heapq.heappush(pq, (val, ind))
                break

            val = (val * multiplier) % MOD
            heapq.heappush(pq, (val, ind))
            k -= 1

        cyclic_base = []
        while pq:
            cyclic_base.append(heapq.heappop(pq))

        # Handle remaining operations
        if k > 0:
            rem_k = k % len(nums)
            cycles = k // len(nums)

            for i in range(len(cyclic_base)):
                val, ind = cyclic_base[i]
                val = (val * power(multiplier, cycles)) % MOD
                cyclic_base[i] = (val, ind)

            for i in range(rem_k):
                val, ind = cyclic_base[i]
                val = (val * multiplier) % MOD
                cyclic_base[i] = (val, ind)

        # Construct the final result
        result = [0] * len(nums)
        for val, ind in cyclic_base:
            result[ind] = val

        return result
