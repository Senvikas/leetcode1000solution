class Solution {
public:
    bool checkInclusion(string s, string t) {
        int len = s.length(), n = t.length();
        if(n < len) return 0;
        vector<int> sa(26, 0);
        for(auto ch: s) sa[ch - 'a']++;
        
        for(int i=0; i<n-len+1; i++)
        {
            vector<int>ta(26, 0);
            for(int j = i; j<i+len; j++)
            {
                int ind = t[j] - 'a';
                ta[ind]++;
            }
            if(sa == ta) return true;
        }
        return false;
    }
};