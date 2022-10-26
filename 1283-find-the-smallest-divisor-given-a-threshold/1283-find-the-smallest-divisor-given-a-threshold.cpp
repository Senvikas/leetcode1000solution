class Solution
{
    bool check(vector<int> &arr, int n, int mid, int t) 
    {
        if(!mid) return false;
        long long sum = 0;
        for(int &a : arr)
        {
            sum += (a/mid + (a%mid == 0? 0 : 1));
        }
        return sum<=t;
    }
    public:
        int smallestDivisor(vector<int> &nums, int threshold)
        {
            int n = nums.size();
            int div = 1;
//this is the catch            //int s = *min_element(nums.begin(), nums.end());
            int s = 1;
            int e = *max_element(nums.begin(), nums.end());

            while (s <= e)
            {
                int mid = s + (e - s) / 2;
                if (check(nums, n, mid, threshold))
                {
                    div = mid;
                    e = mid - 1;
                }
                else
                    s = mid + 1;
            }
            return div;
        }
};