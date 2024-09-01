class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        vector<int> freq(256, 0);

        for(int i=0; i<n2; i++) freq[t[i]]++;

        int right = 0, left = 0, minLen = INT_MAX, cnt = 0, start_ind = -1;
        while(right < n1){
            char ch = s[right];
            if(freq[ch] > 0) cnt++;
            freq[ch]--;

            while(cnt == n2){
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    start_ind = left;
                }
                char left_ch = s[left];
                freq[left_ch]++;
                if(freq[left_ch] > 0) cnt--;
                left++;
            }

            right++;
        }

        return start_ind == -1 ? "" : s.substr(start_ind, minLen);
    }
};