class Solution
{
    public:
        bool detectCapitalUse(string word)
        {
            int n = word.length();
            if (n <= 1) return true;
            bool first_small = word[0] > 'Z';
            if (first_small)
            {
                for (int i = 1; i < n; i++)
                {
                    if (word[i] <= 'Z') return false;
                }
            }
            else
            {
                bool second_small = word[1] > 'Z';
                if (second_small)
                {
                    for (int i = 2; i < n; i++)
                    {
                        if (word[i] <= 'Z') return false;
                    }
                }
                else
                {
                    for (int i = 2; i < n; i++)
                    {
                        if (word[i] > 'Z') return false;
                    }
                }
            }
            return true;
        }
};