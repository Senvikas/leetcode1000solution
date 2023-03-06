class Solution
{
    public:
        int findKthPositive(vector<int> &arr, int k)
        {
            k--;
            vector<int> nums(2001, 0);	// taking 2000 for the last case possible (arr[i]=1000 &k=1000)
            for (auto i: arr) nums[i] = 1;
            for (int i = 1; i < 2001; ++i)
            {
                if (nums[i] == 0)
                {
                    if (k) k--;
                    else return i;	// check for the first missing number after k-1 missing numbers
                }
            }
            return -1;
        }
};