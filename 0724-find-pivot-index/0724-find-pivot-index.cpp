class Solution
{
    public:
        int pivotIndex(vector<int> &nums)
        {
            int n = nums.size();
            int lsum = 0;
            int rsum = 0;
            for (int i = 0; i < n; i++)
            {
                rsum = rsum + nums[i];
            }

            for (int i = 0; i < n; i++)
            {
                rsum = rsum - nums[i];
                if (i == 0)
                {
                    lsum = 0;
                }
                else
                {
                    lsum = lsum + nums[i - 1];
                }
                if (lsum == rsum) return i;
            }
            return -1;
        }
};