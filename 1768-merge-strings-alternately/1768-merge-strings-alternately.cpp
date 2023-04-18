class Solution
{
    public:
        string mergeAlternately(string word1, string word2)
        {
            int i = 0;	//iterator for word1 
            int j = 0;	//iterator for word2
            string ans = "";
           	//iterate while any of the words is not completely covered
            while (i < word1.size() || j < word2.size())
            {
               	//if both words are not iterated completely
                if (i < word1.size() && j < word2.size())
                {
                    ans = ans + word1[i] + word2[j];
                    i++;
                    j++;
                }
               	//if word 1 is completely iterated but not word 2
                if (i == word1.size() && j < word2.size())
                {
                    ans = ans + word2[j];
                    j++;
                }
               	// if word 2 compltely itererated but not word1
                if (j == word2.size() && i < word1.size())
                {
                    ans = ans + word1[i];
                    i++;
                }
            }
            return ans;
        }
};