import java.util.*;

class Solution {
    public long findScore(int[] nums) {
        int n = nums.length;
        long score = 0;

        List<int[]> valInd = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            valInd.add(new int[]{nums[i], i});
        }

        // Sort by value, then by index
        Collections.sort(valInd, (a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);

        boolean[] marked = new boolean[n];

        for (int[] p : valInd) {
            int val = p[0];
            int ind = p[1];

            if (marked[ind]) continue;

            score += val;

            if (ind > 0) marked[ind - 1] = true;
            marked[ind] = true;
            if (ind < n - 1) marked[ind + 1] = true;
        }

        return score;
    }
}
