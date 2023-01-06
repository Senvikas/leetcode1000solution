class Solution
{
    public:
        int maxIceCream(vector<int> &c, int coins)
        {
            int n = c.size();
            sort(c.begin(), c.end());
            if (coins < c[0]) return 0;
            vector<int> pref(n);
            pref[0] = c[0];
            for (int i = 1; i < n; i++)
            {
                pref[i] = c[i] + pref[i - 1];
                if (pref[i] > coins) return i;
            }
            return n;
        }
};