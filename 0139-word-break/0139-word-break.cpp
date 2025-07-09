class Solution {
public:
    bool f(int ind, string &s, vector<string> &dict, int n, vector<int> &dp){
        if(ind > n) return false;
        if(ind == n) return true;

        if(dp[ind] != -1) return dp[ind];

        // from current ind see how many words are present in the dict and take each one of them and find ans for remaining string
        for(auto word: dict){
            int len = word.size();

            // if this len is well within the remaining s (n - ind >= len)
            if(len > n - ind) continue; // word is bigger then the remaining s

            string strInS = s.substr(ind, len);
            if(strInS == word){  // then only check for remaining s
                bool rem = f(ind+len, s, dict, n, dp);
                if(rem) return dp[ind] = true;
            }
        }
        
        return dp[ind] = false;
    }

    bool wordBreak(string s, vector<string>& dict) {
        int n = s.size();
        vector<int> dp(n+1, -1);
        return f(0, s, dict, n, dp);
    }
};