public class Solution {
    const long MOD = (long)1e9 + 7;

    private long Power(long baseValue, long exp) {
        long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) result = (result * baseValue) % MOD;
            baseValue = (baseValue * baseValue) % MOD;
            exp /= 2;
        }
        return result;
    }

    public int[] GetFinalState(int[] nums, int k, int m) {
        if (m == 1) return nums;

        var pq = new SortedSet<(long value, int index)>();
        long maxi = long.MinValue;

        for (int i = 0; i < nums.Length; i++) {
            pq.Add((nums[i], i));
            maxi = Math.Max(maxi, nums[i]);
        }

        while (k > 0) {
            var min = pq.Min;
            pq.Remove(min);

            if (min.value * m > maxi) {
                pq.Add(min);
                break;
            }

            pq.Add(((min.value * m) % MOD, min.index));
            k--;
        }

        var cyclicBase = pq.ToArray();
        if (k > 0) {
            int remK = k % nums.Length;
            int cycles = k / nums.Length;

            for (int i = 0; i < nums.Length; i++) {
                cyclicBase[i] = ((cyclicBase[i].value * Power(m, cycles)) % MOD, cyclicBase[i].index);
            }

            for (int i = 0; i < remK; i++) {
                cyclicBase[i] = ((cyclicBase[i].value * m) % MOD, cyclicBase[i].index);
            }
        }

        int[] result = new int[nums.Length];
        foreach (var (value, index) in cyclicBase) {
            result[index] = (int)value;
        }

        return result;
    }
}
