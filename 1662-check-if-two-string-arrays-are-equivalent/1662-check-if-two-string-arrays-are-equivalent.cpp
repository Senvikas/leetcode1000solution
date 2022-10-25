class Solution
{
    public:
        string makestring(vector<string> v)
        {
            string s = "";
            int n = v.size();
            for (int i = 0; i < n; i++)
                s += v[i];
            return s;
        }

    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        /*
        string a = makestring(word1);
        string b = makestring(word2);

        return a==b;
        */	//approach 2=>
        int n1 = word1.size(), n2 = word2.size();
        int i = 0, j = 0;
        int ind1 = 0, ind2 = 0;
        while (i < n1 && j < n2)
        {
            if (word1[i][ind1] != word2[j][ind2])
                return false;
            else
                ind1++;
            ind2++;
            if (ind1 == word1[i].length())
            {
                ind1 = 0;
                i++;
            }
            if (ind2 == word2[j].length())
            {
                ind2 = 0;
                j++;
            }
        }
        return (i == n1 && j == n2);
    }
};