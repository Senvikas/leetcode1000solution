class Solution
{
    public:
        bool canJump(vector<int> &nums)
        {

            int n = nums.size();
            if(n == 1) return 1;
            int max_reach = nums[0];
            if (max_reach == 0) return 0;
            for (int i = 1; i < n; i++)
            {

                max_reach = max(max_reach - 1, nums[i]);
                if (max_reach == 0 && i != n - 1) return false;
            }
            return true;
        }
};