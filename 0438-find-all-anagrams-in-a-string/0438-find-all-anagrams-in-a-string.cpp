class Solution {
public:
    vector<int> findAnagrams(string t, string s) {
        int len = s.length(), n = t.length();
        if(n < len) return {};
        vector<int> sa(26, 0), ans;
        for(auto ch: s) sa[ch - 'a']++;
        
        for(int i=0; i<n-len+1; i++)
        {
            vector<int>ta(26, 0);
            for(int j = i; j<i+len; j++)
            {
                int ind = t[j] - 'a';
                ta[ind]++;
            }
            if(sa == ta) ans.push_back(i);
        }
        return ans;
    }
};