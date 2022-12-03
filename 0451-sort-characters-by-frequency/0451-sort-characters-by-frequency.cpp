class Solution
{
    public:
        string frequencySort(string s)
        {
            unordered_map<char, int> freq;
            vector<string> v(s.size() + 1, "");
            string res;
            for (char c: s) freq[c]++;
            for (auto &it: freq)
            {
                int n = it.second;
                char c = it.first;
                v[n].append(n, c);
            }
            for (int i = s.size(); i > 0; i--)
            {
                if (!v[i].empty())
                    res.append(v[i]);
            }
            return res;
        }
};