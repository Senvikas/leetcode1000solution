class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int l = 0, r = 0;
        int longest = 0;

        while (r < n) {
            while (l <= r && (long long)nums[r] > (long long)nums[l] * k)
                l++;

            longest = max(longest, r - l + 1);
            r++;
        }

        return n - longest;
    }
};
