public class Solution {
    public long FindScore(int[] nums) {
        int n = nums.Length;
        long score = 0;

        var valInd = new List<(int val, int ind)>();
        for (int i = 0; i < n; i++) {
            valInd.Add((nums[i], i));
        }

        // Sort by value, then index
        valInd.Sort((a, b) => a.val == b.val ? a.ind - b.ind : a.val - b.val);

        bool[] marked = new bool[n];

        foreach (var (val, ind) in valInd) {
            if (marked[ind]) continue;

            score += val;

            if (ind > 0) marked[ind - 1] = true;
            marked[ind] = true;
            if (ind < n - 1) marked[ind + 1] = true;
        }

        return score;
    }
}
