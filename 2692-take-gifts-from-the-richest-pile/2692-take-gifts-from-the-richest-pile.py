class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        gifts = [-gift for gift in gifts]  # Max-heap using negative values
        heapq.heapify(gifts)
        
        while k > 0:
            max_gifts = -heapq.heappop(gifts)
            if max_gifts == 1:
                heapq.heappush(gifts, -1)  # Correctly add 1 back to the heap
                break
            leave = math.isqrt(max_gifts)
            heapq.heappush(gifts, -leave)
            k -= 1
        
        return -sum(gifts)
