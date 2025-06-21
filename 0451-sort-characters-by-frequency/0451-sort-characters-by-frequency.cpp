#include <vector>
#include <algorithm>

class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Count the frequency of each character
        int freq[256] = {0};
        for (char c : s) {
            freq[c]++;
        }
        
        // Step 2: Store characters and their frequencies in a vector
        vector<pair<int, char>> freqChars;
        for (int i = 0; i < 256; i++) {
            if (freq[i] > 0) {
                freqChars.push_back({freq[i], (char)i});
            }
        }
        
        // Step 3: Sort the vector in descending order of frequency
        sort(freqChars.begin(), freqChars.end(), [](const pair<int, char>& a, const pair<int, char>& b) {
            return a.first > b.first;
        });
        
        // Step 4: Build the result string
        string result;
        for (auto& p : freqChars) {
            result.append(string(p.first, p.second));
        }
        
        return result;
    }
};