class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> freq_count(26, 0);
        int window_start = 0, window_end = 0, max_freq = 0, max_length = 0;

        while(window_end < n){
            freq_count[s[window_end] - 'A']++;
            max_freq = max(max_freq, freq_count[s[window_end] - 'A']);

            
            while(window_end - window_start + 1 - max_freq > k){
                freq_count[s[window_start] - 'A']--;
                for(int i=0; i<26; i++) max_freq = max(max_freq, freq_count[i]);
                window_start++;
            }

            if(window_end - window_start + 1 - max_freq <= k) 
                max_length = max(max_length, window_end - window_start + 1);

            window_end++;
        }

        return max_length;
    }
};