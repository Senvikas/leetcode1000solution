class Solution
{
    public:
        string longestCommonPrefix(vector<string> &strs)
        {
            int n = strs.size();
            string ans = strs[0];
            int alen = ans.length();
            for (int i = 1; i < n; i++)
            {
                string word = strs[i];
                int wlen = word.length();
                cout<<alen<<wlen<<endl;
                if (wlen == 0)
                    return "";
                if (ans[0] != word[0]) return "";
                int j = 0;
                for (; j < (alen > wlen ? wlen : alen); j++)
                {
                    if (ans[j] == word[j])
                        continue;
                    else
                    break;
                }
                ans = ans.substr(0, j);
            }
            return ans;
        }
};