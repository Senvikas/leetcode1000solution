class Solution {
public:
    void solve(vector<string> &ans, vector<string> &mapping, string &digits, string tmp, int ind){
        //base case
        if(ind >= digits.size()){
            ans.push_back(tmp);
           // tmp.clear();
            return ;
        }
        
        //get the digit
        int dig = digits[ind] - '0';
        
        //get the corresponding mapping
        string str = mapping[dig];
        
        for(int i=0; i<str.size(); i++){
            tmp += str[i];
            solve(ans, mapping, digits, tmp, ind+1);
            tmp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        solve(ans, mapping, digits, "", 0);
        return ans;
    }
};