class Solution
{
    bool possible(vector<int> &arr, int m, int n, int k, int mid)
    {
        int flowers = 0;
        int bouquets = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= mid)
                flowers++;
            else
                flowers = 0;
            if (flowers >= k)
            {
                bouquets++;
                flowers = 0;
            }
        }
        return bouquets >= m;
    }
    public:
        int minDays(vector<int> &bloomDay, int m, int k)
        {
            long long n = bloomDay.size();	//number of flowers
            if (n/k < m) return -1;
            int ans = -1;
            int s = *min_element(bloomDay.begin(), bloomDay.end());
            int e = *max_element(bloomDay.begin(), bloomDay.end());

            while (s <= e)
            {
                int mid = s + (e - s) / 2;
                if (possible(bloomDay, m, n, k, mid))
                {
                    ans = mid;
                    e = mid - 1;
                }
                else
                    s = mid + 1;
            }
            return ans;
        }
};