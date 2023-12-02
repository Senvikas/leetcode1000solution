class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        
        // Find the median element using nth_element
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int median = nums[n / 2];
        
        // Index mapping function to map an index in the original array to its new position
        auto idx = [n](int i) -> int {
            return (1 + 2 * i) % (n | 1);
        };
        
        // Dutch National Flag algorithm to rearrange the elements
        int left = 0, i = 0, right = n - 1;
        while (i <= right) {
            if (nums[idx(i)] > median) {
                swap(nums[idx(left)], nums[idx(i)]);
                left++;
                i++;
            } else if (nums[idx(i)] < median) {
                swap(nums[idx(right)], nums[idx(i)]);
                right--;
            } else {
                i++;
            }
        }
    }
};
