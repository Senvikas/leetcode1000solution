import java.util.PriorityQueue;

class Solution {
    public double maxAverageRatio(int[][] cls, int extra) {
        PriorityQueue<double[]> maxHeap = new PriorityQueue<>((a, b) -> Double.compare(b[0], a[0]));

        for (int[] cl : cls) {
            int pass = cl[0], total = cl[1];
            double gain = (double)(pass + 1) / (total + 1) - (double)pass / total;
            maxHeap.offer(new double[]{gain, pass, total});
        }

        while (extra-- > 0) {
            double[] top = maxHeap.poll();
            double gain = top[0];
            int pass = (int)top[1];
            int total = (int)top[2];

            pass++;
            total++;

            double newGain = (double)(pass + 1) / (total + 1) - (double)pass / total;
            maxHeap.offer(new double[]{newGain, pass, total});
        }

        double totalSum = 0.0;
        while (!maxHeap.isEmpty()) {
            double[] top = maxHeap.poll();
            int pass = (int)top[1];
            int total = (int)top[2];
            totalSum += (double)pass / total;
        }

        return totalSum / cls.length;
    }
}
