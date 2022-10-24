class Solution
{
    
    //PROBLEM RELATED WITH MERGE SORT
    public:
        int Merge(vector<int> &nums, int l, int m, int h)
        {
            int ans = 0;
            int j = m + 1;
            for (int i = l; i <= m; i++)
            {
                while (j <= h && nums[i] > (long long) 2 *nums[j])
                {
                    j++;
                }
                ans += (j - (m + 1));
            }

            vector<int> tmp;
            int left = l, right = m + 1;

            while (left <= m && right <= h)
            {

                if (nums[left] <= nums[right])
                {
                    tmp.push_back(nums[left++]);
                }
                else
                {
                    tmp.push_back(nums[right++]);
                }
            }

            while (left <= m)
            {
                tmp.push_back(nums[left++]);
            }
            while (right <= h)
            {
                tmp.push_back(nums[right++]);
            }

            for (int i = l; i <= h; i++)
            {
                nums[i] = tmp[i - l];
            }
            return ans;
        }
    //Do brush up merge sort algo
    int MergeSort(vector<int> &nums, int l, int h)
    {

        if (l >= h) return 0;
        int m = (l + h) / 2;
        int invert = MergeSort(nums, l, m);
        invert += MergeSort(nums, m + 1, h);
        invert += Merge(nums, l, m, h);
        return invert;
    }

    int reversePairs(vector<int> &nums)
    {
        return MergeSort(nums, 0, nums.size() - 1);
    }
};