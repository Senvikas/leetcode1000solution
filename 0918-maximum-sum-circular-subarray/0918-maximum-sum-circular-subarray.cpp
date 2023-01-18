class Solution
{
    public:
        int maxSubarraySumCircular(vector<int> &nums)
        {
            int n = nums.size();
           	// Initialize max_so_far, min_so_far, current_max, current_min, and total
            int max_so_far = nums[0], min_so_far = nums[0], current_max = 0, current_min = 0, total = 0;
            for (auto &i: nums)
            {
               	// update the current_max and current_min
                current_max = max(current_max + i, i);
                current_min = min(current_min + i, i);
                total += i;
               	// update the max_so_far and min_so_far
                max_so_far = max(max_so_far, current_max);
                min_so_far = min(min_so_far, current_min);
            }
           	// return the max of max_so_far and total-min_so_far if max_so_far is greater than 0, else return max_so_far
            return max_so_far > 0 ? max(max_so_far, total - min_so_far) : max_so_far;
        }
};