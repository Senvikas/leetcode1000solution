class Solution
{
    public:
        string getHint(string secret, string guess)
        {
            unordered_map<int, int> a_count, b_count;
            int n = min(secret.length(), guess.length());
            int a = 0, b = 0;
            for (int i = 0; i < n; i++)
            {
                if (secret[i] == guess[i]) a++;
                else
                {
                    if (b_count[secret[i]] > 0)
                    {
                        b++;
                        b_count[secret[i]]--;
                    }
                    else
                    {
                        a_count[secret[i]]++;
                    }
                    if (a_count[guess[i]] > 0)
                    {
                        b++;
                        a_count[guess[i]]--;
                    }
                    else
                    {
                        b_count[guess[i]]++;
                    }
                }
            }

            string ans = "";
            ans += to_string(a);
            ans += 'A';
            ans += to_string(b);
            ans += "B";
            return ans;
        }
};