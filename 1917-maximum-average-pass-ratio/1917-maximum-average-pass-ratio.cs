using System;
using System.Collections.Generic;

public class Solution {
    public double MaxAverageRatio(int[][] cls, int extra) {
        var maxHeap = new PriorityQueue<(double gain, int pass, int total), double>(
            Comparer<double>.Create((a, b) => b.CompareTo(a))
        );

        foreach (var cl in cls) {
            int pass = cl[0], total = cl[1];
            double gain = (double)(pass + 1) / (total + 1) - (double)pass / total;
            maxHeap.Enqueue((gain, pass, total), gain);
        }

        while (extra-- > 0) {
            var (gain, pass, total) = maxHeap.Dequeue();

            pass++;
            total++;

            double newGain = (double)(pass + 1) / (total + 1) - (double)pass / total;
            maxHeap.Enqueue((newGain, pass, total), newGain);
        }

        double totalSum = 0.0;
        while (maxHeap.Count > 0) {
            var (_, pass, total) = maxHeap.Dequeue();
            totalSum += (double)pass / total;
        }

        return totalSum / cls.Length;
    }
}
