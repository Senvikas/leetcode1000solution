class Solution {
    public int minimumSize(int[] nums, int maxOperations) {
        int low = 1, high = getMax(nums);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (tryBreaking(nums, mid, maxOperations)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    private boolean tryBreaking(int[] nums, int mxBalls, int tries) {
        for (int num : nums) {
            if (num < mxBalls) {
                continue;
            }

            if ((num / (tries + 1)) <= mxBalls) {
                int used = (num / mxBalls) - (num % mxBalls == 0 ? 1 : 0);
                tries -= used;

                if (tries < 0) {
                    return false;
                }
            } else {
                return false;
            }
        }

        return true;
    }

    private int getMax(int[] nums) {
        int max = nums[0];
        for (int num : nums) {
            if (num > max) {
                max = num;
            }
        }
        return max;
    }
}
