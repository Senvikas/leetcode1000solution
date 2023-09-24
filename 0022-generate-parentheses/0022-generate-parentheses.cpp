class Solution {
public:
    void solve(vector<string> &ans, int n, int open, int close, string paren){
        if(paren.size() == n*2){
            ans.push_back(paren);
            return;
        }
        
        if(open < n) solve(ans, n, open+1, close, paren+"(");
        if(close < open) solve(ans, n, open, close+1, paren+")");
        return ;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans, n, 0, 0, "");
        return ans;
    }
};