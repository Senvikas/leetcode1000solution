import heapq

class Solution:
    def maxAverageRatio(self, cls: List[List[int]], extra: int) -> float:
        maxHeap = []
        
        for passes, total in cls:
            gain = (passes + 1) / (total + 1) - passes / total
            heapq.heappush(maxHeap, (-gain, [passes, total]))  # Use negative for max-heap behavior
        
        while extra > 0:
            gain, cl = heapq.heappop(maxHeap)
            passes, total = cl
            passes += 1
            total += 1
            
            new_gain = (passes + 1) / (total + 1) - passes / total
            heapq.heappush(maxHeap, (-new_gain, [passes, total]))
            extra -= 1
        
        total_sum = 0.0
        while maxHeap:
            _, cl = heapq.heappop(maxHeap)
            passes, total = cl
            total_sum += passes / total
        
        return total_sum / len(cls)
