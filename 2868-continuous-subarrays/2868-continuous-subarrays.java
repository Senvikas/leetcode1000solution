import java.util.*;

class Solution {
    public long continuousSubarrays(int[] nums) {
        long ans = 0;
        int l = 0, r = 0, n = nums.length;
        Map<Integer, Integer> map = new HashMap<>(); // value -> frequency

        while (r < n) {
            map.put(nums[r], map.getOrDefault(nums[r], 0) + 1);

            int maxi = Integer.MIN_VALUE;
            int mini = Integer.MAX_VALUE;

            for (int key : map.keySet()) {
                maxi = Math.max(maxi, key);
                mini = Math.min(mini, key);
            }

            while (maxi - mini > 2) {
                map.put(nums[l], map.get(nums[l]) - 1);
                if (map.get(nums[l]) == 0) {
                    map.remove(nums[l]);
                }
                l++;

                maxi = Integer.MIN_VALUE;
                mini = Integer.MAX_VALUE;

                for (int key : map.keySet()) {
                    maxi = Math.max(maxi, key);
                    mini = Math.min(mini, key);
                }
            }

            ans += (r - l + 1);
            r++;
        }

        return ans;
    }
}
