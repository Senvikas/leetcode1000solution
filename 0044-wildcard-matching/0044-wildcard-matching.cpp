class Solution {
public:
    bool f(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        //base case
        //1. if s ended, remaining pattern have to be "*******"
        if(i==0){     //shifting of indexes
            while(j>=1){
                if(p[j-1] != '*') return false;
                j--;
            }
            return true;
        }
        
        //2. pattern ended, ex  s="ab", p="b"  => s="a", p="" could not match ret false
        if(j==0) return false;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        //1. if matches
        if(s[i-1] == p[j-1]){
            return dp[i][j] = f(i-1, j-1, s, p, dp);
        }
        
        //2. if does not match but pattern is having '?', they still would match
        if(p[j-1] == '?'){
            return dp[i][j] = f(i-1, j-1, s, p, dp);
        }
        
        //3. if does not match but pattern is having '*', * could become a matching char or an empty seq, consider both options.
        if(p[j-1] == '*'){
            bool matchingChar = f(i-1, j, s, p, dp);
            bool emptySequence = f(i, j-1, s, p, dp);
            
            return dp[i][j] = matchingChar || emptySequence;
        }
        
        //4. neither matched nor had '?' nor '*', means case is like s="a", p="b"
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return f(m, n, s, p, dp);
    }
};