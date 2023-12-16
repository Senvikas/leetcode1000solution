class Solution {
public:
    bool isAnagram(string s, string t) {
        int sl = s.size();
        int tl = t.size();
        if(sl != tl) return false;
        
        vector<int> sv(26, 0);
        for(auto ch : s)
            sv[ch - 'a']++;
        
        for(auto ch : t){
            if(sv[ch - 'a'] == 0) return false;
            sv[ch - 'a']--;
        }
        return true;
    }
};