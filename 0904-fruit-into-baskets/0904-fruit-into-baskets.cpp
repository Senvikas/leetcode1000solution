class Solution
{
    public:
        int totalFruit(vector<int> &fruits)
        {
            map<int, int> mp;
            int ans = 0, mx = -1;
            int i = 0, j = 0;
            while (i < fruits.size())
            {
                mp[fruits[i]]++;
                if (mp.size() == 3)
                {
                    mx = max(ans, mx);
                    while (j < i)
                    {
                        mp[fruits[j]]--;
                        ans--;
                        if (mp[fruits[j]] == 0)
                        {
                            mp.erase(fruits[j]);
                            j++;
                            break;
                        }
                        j++;
                    }
                }
                ans++;
                i++;
            }
            mx = max(ans, mx);
            cout << i;
            return mx;
        }
};