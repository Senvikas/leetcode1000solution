class Solution
{
    string findstring(int n)
    {
       	//base case
        if (n == 1)
            return "0";
        string s = findstring(n - 1);
        string ans = s + "1";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0') s[i] = '1';
            else s[i] = '0';
        }
        reverse(s.begin(), s.end());
        ans += s;
        return ans;
    }

    public:
        char findKthBit(int n, int k)
        {
            string ans = findstring(n);
            return ans[k - 1];
        }
};