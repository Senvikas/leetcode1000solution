class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = 0;
        string ans;
        while(i<n){
            string word = "";
            while(s[i] != ' '){
                word.push_back(s[i]);
                i++;
                if(i > n-1) break;
            }
            i++;
            reverse(word.begin(), word.end());
            ans += word; if(i<n)ans.push_back(' ');
        }
        return ans;
    }
};