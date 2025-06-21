class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> freq(26, 0);
        int maxFreq = 0; // Tracks the maximum frequency of any character in the current window
        int maxLen = 0;  // Tracks the maximum length of valid window found so far
        
        int left = 0;
        for (int right = 0; right < n; right++) {
            char currentChar = s[right];
            freq[currentChar - 'A']++;
            maxFreq = max(maxFreq, freq[currentChar - 'A']);
            
            // Calculate the number of replacements needed: window_size - maxFreq
            // If replacements needed > k, shrink the window from the left
            while ((right - left + 1 - maxFreq) > k) {
                char leftChar = s[left];
                freq[leftChar - 'A']--;
                left++;
                // Note: We don't decrement maxFreq here because it doesn't affect the result
                // The window can only get smaller, so maxFreq might stay the same or decrease
            }
            
            // Update the maximum valid window size
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};