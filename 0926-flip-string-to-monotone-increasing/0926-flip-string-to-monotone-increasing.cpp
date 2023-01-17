class Solution
{
    public:
        int minFlipsMonoIncr(string s)
        {
            int string_length = s.length();	// string_length is the length of the input string
            int ones_count = 0;	// ones_count keeps track of number of '1' in the string from the start
            int flips_count = 0;	// flips_count is the number of flips required
            for (int i = 0; i < string_length; i++)
            {
                if (s[i] == '1')
                {
                    ones_count++;
                }
                else
                {
                    flips_count = min(ones_count, flips_count + 1);	// update the number of flips required
                }
            }
            return flips_count;	// return the minimum number of flips
        }
};