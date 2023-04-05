class Solution {

    public int minimizeArrayValue(int[] nums) {
        int min = 0;
        int max = Integer.MIN_VALUE;

        for (int n : nums) {
            max = Math.max(max, n);
        }

        int ans = Integer.MAX_VALUE;

        while (min <= max) {
            int mid = min + (max - min) / 2;

            boolean canAdjust = checkIfCanAdjust(nums, mid);

            if (canAdjust) {
                ans = mid;
                max = mid - 1;
            } else {
                min = mid + 1;
            }
        }

        return ans;
    }

    private boolean checkIfCanAdjust(int[] nums, int target) {
        long buffer = 0;

        for (int i = 0; i < nums.length - 1; i++) {
            long current = nums[i];

            if (current > target && current - buffer > target) {
                return false;
            }

            buffer = target - (current - buffer);
        }

        long last = nums[nums.length - 1];

        return last <= target || last - buffer <= target;
    }
}
