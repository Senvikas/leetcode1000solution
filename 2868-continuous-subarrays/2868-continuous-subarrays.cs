using System;
using System.Collections.Generic;

public class Solution {
    public long ContinuousSubarrays(int[] nums) {
        long ans = 0;
        int l = 0, r = 0, n = nums.Length;
        Dictionary<int, int> freq = new Dictionary<int, int>();

        while (r < n) {
            if (!freq.ContainsKey(nums[r])) freq[nums[r]] = 0;
            freq[nums[r]]++;

            int maxi = int.MinValue;
            int mini = int.MaxValue;

            foreach (var key in freq.Keys) {
                maxi = Math.Max(maxi, key);
                mini = Math.Min(mini, key);
            }

            while (maxi - mini > 2) {
                freq[nums[l]]--;
                if (freq[nums[l]] == 0) {
                    freq.Remove(nums[l]);
                }
                l++;

                maxi = int.MinValue;
                mini = int.MaxValue;

                foreach (var key in freq.Keys) {
                    maxi = Math.Max(maxi, key);
                    mini = Math.Min(mini, key);
                }
            }

            ans += (r - l + 1);
            r++;
        }

        return ans;
    }
}
