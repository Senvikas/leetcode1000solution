/*
class Solution
{
    public:
        int maxProduct(vector<int> &nums)
        {
            int n = nums.size();
            int mprod = nums[0];
            int maxtillhere = nums[0], mintillhere = nums[0];

            for (int i = 1; i < n; i++)
            {
                int tmp = maxtillhere;
                maxtillhere = max({ nums[i],
                    nums[i] *maxtillhere,
                    nums[i] *mintillhere });
                mintillhere = min({ nums[i],
                    nums[i] *tmp,
                    nums[i] *mintillhere });
                mprod = max(mprod, maxtillhere);
            }
            return mprod;
        }
};

*/ 
    //approach 2
    class Solution
{
    public:

        int maxProductSubArray(vector<int> &nums)
        {
            int maxLeft = nums[0];
            int maxRight = nums[0];

            int prod = 1;

            bool zero = false;

            for (auto i: nums)
            {
                prod *= i;
                if (i == 0)
                {
                    zero = true;
                    prod = 1;
                    continue;
                }
                maxLeft = max(maxLeft, prod);
            }

            prod = 1;

            for (int j = nums.size() - 1; j >= 0; j--)
            {
                prod *= nums[j];
                if (nums[j] == 0)
                {
                    zero = true;
                    prod = 1;
                    continue;
                }
                maxRight = max(maxRight, prod);
            }

            if (zero) return max(max(maxLeft, maxRight), 0);
            return max(maxLeft, maxRight);
        }

    int maxProduct(vector<int> &nums)
    {

        return maxProductSubArray(nums);
    }
};
