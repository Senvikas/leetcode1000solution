public class Solution {
    public long PickGifts(int[] gifts, int k) {
        PriorityQueue<int, int> pq = new PriorityQueue<int, int>(Comparer<int>.Create((a, b) => b - a));
        
        foreach (int gift in gifts) {
            pq.Enqueue(gift, gift);
        }
        
        while (k-- > 0 && pq.Count > 0) {
            int maxGifts = pq.Dequeue();
            if (maxGifts == 1) {
                pq.Enqueue(1, 1); // Re-add 1 back to the queue
                break;
            }
            
            int leave = (int)Math.Sqrt(maxGifts);
            pq.Enqueue(leave, leave);
        }
        
        long ans = 0;
        while (pq.Count > 0) {
            ans += pq.Dequeue();
        }
        
        return ans;
    }
}
