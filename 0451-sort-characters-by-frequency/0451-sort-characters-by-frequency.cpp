class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> frequencyMap;
        
        // Count the frequency of each character
        for (char c : s) {
            frequencyMap[c]++;
        }
        
        // Store the characters and their frequencies in a vector
        vector<pair<int, char>> freqVec;
        for (const auto& entry : frequencyMap) {
            freqVec.push_back({entry.second, entry.first});
        }
        
        // Sort the vector by frequency in descending order
        sort(freqVec.begin(), freqVec.end(), [](const pair<int, char>& a, const pair<int, char>& b) {
            return a.first > b.first;
        });
        
        // Build the result string
        string result;
        for (const auto& entry : freqVec) {
            result.append(entry.first, entry.second);
        }
        
        return result;
    }
};
