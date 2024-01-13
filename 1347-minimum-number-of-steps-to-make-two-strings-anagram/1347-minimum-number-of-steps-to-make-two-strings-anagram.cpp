class Solution {
public:
    int minSteps(string& s, string& t) {
        vector<int> sCount(26), tCount(26);
        for(int i=0; i<s.size(); i++){
            sCount[s[i]-'a']++;
            tCount[t[i]-'a']++;
        }
        int ans = 0;
        for(int i=0; i<26; i++){
            if (tCount[i] > sCount[i]){
                ans += tCount[i]-sCount[i];
            }
        }
        return ans;
    }
};
