public class Solution {
    public bool[] IsArraySpecial(int[] nums, int[][] queries) {
        int n = nums.Length;
        List<int> index = new List<int>();
        bool prev = nums[0] % 2 == 1;

        // Find indices where parity is the same
        for (int i = 1; i < n; i++) {
            bool curr = nums[i] % 2 == 1;
            if (prev == curr) {
                index.Add(i - 1);
            }
            prev = curr;
        }

        // Process queries
        bool[] result = new bool[queries.Length];
        for (int q = 0; q < queries.Length; q++) {
            int from = queries[q][0], to = queries[q][1];
            int left = 0, right = index.Count - 1, found = -1;

            // Binary search to find the first index >= 'from'
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (index[mid] >= from) {
                    found = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            // Check if the subarray is special
            result[q] = (found == -1 || to <= index[found]);
        }

        return result;
    }
}
