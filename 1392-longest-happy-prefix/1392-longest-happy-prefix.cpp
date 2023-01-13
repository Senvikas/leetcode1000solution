class Solution
{
    public:
       	// This function returns the longest happy prefix of the given text
        string longestPrefix(string text)
        {
           	// Initialize a vector to store the prefix matches
            vector<int> prefix_matches(text.size(), 0);
           	// Initialize indices to traverse the text
            int text_index = 1, prefix_index = 0;
           	// Iterate through the text
            while (text_index < text.size())
            {
               	// If the current character in text matches the current character in the prefix
                if (text[text_index] == text[prefix_index])
                {
                   	// Update the prefix matches vector
                    prefix_matches[text_index] = prefix_index + 1;
                   	// Move the indices forward
                    text_index++;
                    prefix_index++;
                }
                else
                {
                   	// If the prefix index is 0, set the prefix match to 0 and move the text index forward
                    if (prefix_index == 0)
                    {
                        prefix_matches[text_index] = 0;
                        text_index++;
                    }
                    else
                    {
                       	// If the prefix index is not 0, set the prefix index to the value in the prefix matches vector
                        prefix_index = prefix_matches[prefix_index - 1];
                    }
                }
            }
           	// The last value in the prefix matches vector is the length of the longest happy prefix
            int match_length = prefix_matches.back();
           	// Return the substring of text from the beginning to the length of the longest happy prefix
            return text.substr(0, match_length);
        }
};