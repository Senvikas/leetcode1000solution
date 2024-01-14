class Solution
{
    public:
        bool closeStrings(string word1, string word2)
        {
            int l1 = word1.size(), l2 = word2.size();
            if (l1 != l2) return false;
            map<char, int> mp1, mp2;
            for (auto &c: word1)
                mp1[c]++;
            for (auto &c: word2)
                mp2[c]++;

            for (auto &c: word2)
                if (mp1.find(c) == mp1.end()) return false;

            vector<int> v1, v2;
            for (auto &it: mp1)
                v1.push_back(it.second);
            for (auto &it: mp2)
                v2.push_back(it.second);

            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end());

            return v1 == v2;
        }
};