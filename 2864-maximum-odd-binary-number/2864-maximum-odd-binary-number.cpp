class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int ones = 0;
        for(auto ch : s){
            if(ch == '1') ones++;
        }
        string ans  = "";
        for(int i=0; i<ones-1; i++) ans.push_back('1');
        for(int i=0; i<n-ones; i++) ans.push_back('0');
        ans.push_back('1');
        return ans;
    }
};