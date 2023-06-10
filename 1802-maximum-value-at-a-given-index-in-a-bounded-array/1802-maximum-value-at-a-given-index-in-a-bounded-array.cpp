class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        long left_sum = 0;
        long right_sum = 0;
        long right_count = n - index - 1;
        long left_count = index;
        int result = 0;
        int low = 1;
        int high = maxSum;

        while (low <= high) {
            long mid = low + (high - low) / 2;
            long sum = mid;
            long m = mid - 1;

            if (right_count <= m)
                right_sum = m * (m + 1) / 2 - (m - right_count) * (m - right_count + 1) / 2;
            else
                right_sum = m * (m + 1) / 2 + 1 * (right_count - m);

            if (left_count <= m)
                left_sum = m * (m + 1) / 2 - (m - left_count) * (m - left_count + 1) / 2;
            else
                left_sum = m * (m + 1) / 2 + 1 * (left_count - m);

            sum += left_sum + right_sum;

            if (sum <= maxSum) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }
};
