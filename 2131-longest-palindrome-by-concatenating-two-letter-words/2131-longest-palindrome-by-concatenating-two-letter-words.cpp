class Solution
{

    public:
        int longestPalindrome(vector<string> &words)
        {
            int n = words.size();
            int ans = 0;
            int len = 0;

            map<string, int> mp;
            for (auto &x: words)
                mp[x]++;

            bool flag = false;
            for (auto &pair: mp)
            {
                string str = pair.first;
                if (str[0] == str[1])
                {
                   	//odd number
                    if (pair.second % 2)
                    {
                        len += pair.second - 1;
                        flag = true;
                    }
                    else
                    {
                        len += pair.second;
                    }
                    mp.erase(pair.first);
                }
                else
                {
                    reverse(str.begin(), str.end());
                    if (mp.find(str) != mp.end())
                    {
                        ans += 4* min(mp[str], pair.second);
                    }
                    mp.erase(str);
                    mp.erase(pair.first);
                }
            }

            if (flag)
                ans += len *2 + 2;
            else
                ans += len * 2;
            return ans;
        }
};