class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;
        for(int i=0; i<s.length(); i++) {
            mp[s[i]]++;
        }
        string ans = "";
        for(int i=0; i<order.length(); i++) {
            while(mp[order[i]]--) {
                ans += order[i];
            }
        }
        for(int i=0; i<s.length(); i++) {
            while(mp[s[i]]>0) {
                ans += s[i];
                mp[s[i]]--;
            }
        }
        return ans;
    }
};