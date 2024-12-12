class Solution {
    public long pickGifts(int[] gifts, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        
        for (int gift : gifts) {
            pq.add(gift);
        }
        
        while (!pq.isEmpty() && k-- > 0) {
            int maxGifts = pq.poll();
            if (maxGifts == 1)
            {
                pq.add(1);
                break;                
            } 
            int leave = (int) Math.sqrt(maxGifts);
            pq.add(leave);
        }
        
        long ans = 0;
        while (!pq.isEmpty()) {
            ans += pq.poll();
        }
        
        return ans;
    }
}
