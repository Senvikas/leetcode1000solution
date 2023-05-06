class Solution
{
    public:
        int numSubseq(vector<int> &nums, int target)
        {
            int n = nums.size();
            int m = 1e9 + 7;
            sort(nums.begin(), nums.end());
            vector<int> p(n, 1);
            p[0] = 1;
            for (int i = 1; i < n; ++i)
            {
                p[i] = (p[i - 1] *2) % m;
            }
            int a = 0;
            int l = 0;
            int r = n - 1;
            while (l <= r)
            {
                if (nums[l] + nums[r] <= target)
                {
                    a += p[r - l];
                    a %= m;
                    l++;
                }
                else
                {
                    r--;
                }
            }
            return a;
        }
};