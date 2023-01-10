class Solution
{
    public:
        int findUnsortedSubarray(vector<int> &arr)
        {
            int n = arr.size();
            int si = 0;
            int ei = 0;
            for (int i = 0; i < n - 1; i++)
            {
                if (arr[i] > arr[i + 1])
                {
                    si = i;
                    break;
                }
            }
            for (int i = n - 1; i >= 1; i--)
            {
                if (arr[i] < arr[i - 1])
                {
                    ei = i;
                    break;
                }
            }
            int mini = 1e9, maxi = -1e9;
            for (int i = si; i <= ei; i++)
            {
                mini = min(arr[i], mini);
                maxi = max(maxi, arr[i]);
            }

            for (int i = si; i >= 0; i--)
            {
                if (arr[i] > mini) si = i;
                else break;
            }
            for (int i = ei + 1; i < n; i++)
            {
                if (arr[i] < maxi) ei = i;
                else break;
            }
            cout << mini << maxi << si << ei << endl;
            if (ei == 0) return 0;
            return ei - si + 1;
        }
};