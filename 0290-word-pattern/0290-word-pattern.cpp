class Solution
{
    public:
        bool wordPattern(string p, string s)
        {
            map<char, string> mp;
            map<string, char> mp1;
            int j = 0;
            for (int i = 0; i < p.length(); i++)
            {
                
                if (j >= s.length()) return false;
               	//finding word
                string word = "";
                while (s[j] != ' ')
                {
                    word += s[j];
                    j++;
                    if (j == s.length()) break;
                }
                if (word == "") return false;
                if (i == p.length()-1 && j != s.length()) return false;
                j++;
                
                if (mp.find(p[i]) == mp.end() && mp1.find(word) == mp1.end())
                {
                    mp[p[i]] = word;
                    mp1[word] = p[i];
                }
                else
                {
                    if (mp[p[i]] != word || mp1[word] != p[i]) return false;
                }
            }
            return true;
        }
};