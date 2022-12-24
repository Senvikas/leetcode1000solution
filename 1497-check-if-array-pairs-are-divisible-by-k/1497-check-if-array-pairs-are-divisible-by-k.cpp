class Solution
{
    public:
        bool canArrange(vector<int> &arr, int k)
        {
            int n = arr.size();
            unordered_map<int, int> mp;

            for (int i = 0; i < n; i++)
            {
                int rem = ((arr[i] % k) + k) % k;	// adding k will cover the case of any negative value
                mp[rem]++;
            }

            for (auto it: mp)
            {
                if (it.first == 0)
                {
                    if (it.second % 2 != 0) return false;
                }
                else
                {
                    if (mp.find(k - it.first) == mp.end()) return false;
                    if (mp[(k - it.first)] != it.second) return false;
                }
            }
            return true;
        }
};