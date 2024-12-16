class Solution {
    static final long MOD = (long) 1e9 + 7;

    private long power(long base, long exp) {
        long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

    public int[] getFinalState(int[] nums, int k, int m) {
        if (m == 1) return nums;

        // Priority Queue: Sort by value first, then by index for stability
        PriorityQueue<long[]> pq = new PriorityQueue<>(
            (a, b) -> a[0] != b[0] ? Long.compare(a[0], b[0]) : Long.compare(a[1], b[1])
        );

        int n = nums.length;
        long maxi = Long.MIN_VALUE;

        for (int i = 0; i < n; i++) {
            pq.add(new long[] {nums[i], i});
            maxi = Math.max(maxi, nums[i]);
        }

        while (k > 0) {
            long[] top = pq.poll();
            long val = top[0];
            int ind = (int) top[1];

            if (val * m > maxi) {
                pq.add(new long[] {val, ind});
                break;
            }

            val = (val * m) % MOD;
            pq.add(new long[] {val, ind});
            k--;
        }

        long[][] cyclicBase = new long[n][2];
        int idx = 0;
        while (!pq.isEmpty()) {
            cyclicBase[idx++] = pq.poll();
        }

        if (k > 0) {
            int remK = k % n;
            int cycles = k / n;

            for (int i = 0; i < n; i++) {
                cyclicBase[i][0] = (cyclicBase[i][0] * power(m, cycles)) % MOD;
            }

            for (int i = 0; i < remK; i++) {
                cyclicBase[i][0] = (cyclicBase[i][0] * m) % MOD;
            }
        }

        int[] result = new int[n];
        for (long[] entry : cyclicBase) {
            result[(int) entry[1]] = (int) (entry[0] % MOD);
        }

        return result;
    }
}
