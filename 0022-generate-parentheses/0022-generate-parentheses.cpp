class Solution {
    void solve(string curr, vector<string> &ans, int open, int close, int n)
    {
        if(curr.length() == 2*n)
        {
            ans.push_back(curr);
            return ;
        }
        if(open < n)solve(curr+"(" , ans, open+1, close, n);
        if(close < open)solve(curr+")" , ans, open , close+1, n);
        return ;
    }
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve("(" , ans, 1, 0, n);
        return ans;
    }
};