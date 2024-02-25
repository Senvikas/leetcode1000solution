class Solution {
public:
    static bool comp(string &a, string &b){
        return a.size() < b.size();
    }
    
    bool checkCond(string &curr, string &prev){
        int m = curr.size(), n = prev.size();
        if(m != n + 1) return false;
        
        int first = 0, second = 0;
        
        while(first < m ){
            if(prev[second] == curr[first]) first++, second++;
            else first++;
        }
        

        return first == m && second == n;

    }
    
    int algorithmic(vector<string> &words){
        int n = words.size();
        vector<int> dp(n, 1);
        
        sort(words.begin(), words.end(), comp); // Sort the input array.


        int maxi = 1;
        
        for(int ind=0; ind<n; ind++){
            for(int prev=0; prev<ind; prev++){
                if(checkCond(words[ind], words[prev]) && dp[ind] < 1 + dp[prev])
                {
                    dp[ind] =  1 + dp[prev];
                    
                    if(dp[ind] > maxi) {
                        maxi = dp[ind];
                    }
                }
            }
        }

        
        return maxi;
    }
    
    int longestStrChain(vector<string>& words) {
        return algorithmic(words);
    }
};