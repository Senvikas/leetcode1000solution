class Solution
{
    public:
        vector<int> shuffle(vector<int> &nums, int n)
        {
            int ind1 = 0, ind2 = n;
            vector<int> ans;
            for (int i = 0; i < n; i++)
            {
                ans.push_back(nums[ind1]);
                ans.push_back(nums[ind2]);
                ind1++;
                ind2++;
            }

            return ans;
        }
};