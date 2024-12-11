class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = 0, n = nums.size(), ans = 0;

        while(r < n)
        {
            // window expand

            // shrink
            while(nums[r] - nums[l] > 2 * k)
            {
                l++;
            }

            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};