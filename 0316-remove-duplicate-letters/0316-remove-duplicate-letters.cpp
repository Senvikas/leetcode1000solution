class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0); // Use 26 instead of 25 for lowercase English letters
        vector<bool> used(26, false);
        string ans = "";

        // Count the frequency of each character in s
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        for (char ch : s) {
            freq[ch - 'a']--; // Decrement the frequency of the current character

            if (used[ch - 'a']) {
                continue; // If this character is already in the answer, skip it
            }

            // Remove characters from the end of ans as long as they are greater than the current character
            while (!ans.empty() && ans.back() > ch && freq[ans.back() - 'a'] > 0) {
                used[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(ch);
            used[ch - 'a'] = true;
        }

        return ans;
    }
};
