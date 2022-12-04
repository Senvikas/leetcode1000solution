typedef long long ll;
class Solution
{
    public:
        int minimumAverageDifference(vector<int> &nums)
        {
            if (nums.size() == 1)
                return 0;

            ll min_diff = INT_MAX, index;

            ll n = nums.size();

            ll sum_from_beg = 0, sum_from_end = 0;

           	// calculate the sum of whole array
            for (ll i = 0; i < n; i++)
                sum_from_end += nums[i];

            for (ll i = 0; i < n; i++)
            {

                sum_from_beg += nums[i];
                sum_from_end -= nums[i];
                ll count1 = i + 1, count2 = n - i - 1;

                ll sum1 = 0, sum2 = 0;
                if (count1 != 0)
                    sum1 = sum_from_beg / count1;

                if (count2 != 0)
                    sum2 = sum_from_end / count2;
                int ab = abs(sum1 - sum2);

                if (ab < min_diff)
                {
                    min_diff = ab;
                    index = i;
                }
            }
            return index;
        }
};