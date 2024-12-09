class Solution {
    public boolean[] isArraySpecial(int[] nums, int[][] queries) {
        int n = nums.length;
        boolean prev = (nums[0] % 2 == 1);
        List<Integer> index = new ArrayList<>();
        for (int i = 1; i < n; i++) {
            boolean curr = (nums[i] % 2 == 1);
            if (prev == curr) {
                index.add(i - 1);
            }
            prev = curr;
        }
        boolean[] ans = new boolean[queries.length];
        for (int q = 0; q < queries.length; q++) {
            int from = queries[q][0], to = queries[q][1];
            int left = 0, right = index.size() - 1, found = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (index.get(mid) >= from) {
                    found = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            ans[q] = (found == -1 || to <= index.get(found));
        }
        return ans;
    }
}
