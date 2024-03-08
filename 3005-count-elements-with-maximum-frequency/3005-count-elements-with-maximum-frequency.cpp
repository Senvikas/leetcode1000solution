class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101, 0);
        
        // Count the frequency of each element
        for (int ele : nums) {
            freq[ele]++;
        }
        
        // Sort the elements in decreasing order of frequency
        sort(freq.begin(), freq.end(), greater<int>());
        
        int maxFreq = freq[0]; // Maximum frequency
        int maxFreqElements = 0; // Number of elements with maximum frequency
        
        // Count the number of elements having maximum frequency
        for (int f : freq) {
            if (f == maxFreq) {
                maxFreqElements++;
            } else {
                break; // If the frequency decreases, stop counting
            }
        }
        
        // Calculate the result (maximum frequency * number of elements with maximum frequency)
        return maxFreq * maxFreqElements;
    }
};
