class Solution {
public:
    int f(int ind, int m, int n, vector<string> &strs, vector<vector<vector<int>>> &dp){
        //base case
        if(m < 0 && n < 0) return 0;
        if(ind < 0) return 0;
        if(ind == 0){
            string str = strs[0];

            int cnt0 = count(str.begin(), str.end(), '0');
            int cnt1 = str.size() - cnt0;

            if(cnt0 <= m && cnt1 <= n){
                return 1;
            }

            return 0;
        }

        if(dp[ind][m][n] != -1) return dp[ind][m][n];

        int notPick = f(ind-1, m, n, strs, dp);
        int pick = 0;

        string str = strs[ind];

        int cnt0 = count(str.begin(), str.end(), '0');
        int cnt1 = str.size() - cnt0;

        if(cnt0 <= m && cnt1 <= n){
            pick = 1 + f(ind-1, m-cnt0, n-cnt1, strs, dp);
        }

        return dp[ind][m][n] = max(pick, notPick);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<vector<int>>> dp(len, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        // return f(len - 1, m, n, strs, dp);

        auto str = strs[0];
        int cnt0 = count(str.begin(), str.end(), '0');
        int cnt1 = str.size() - cnt0;

        for(int mi=cnt0; mi<=m; mi++){
            for(int nj=cnt1; nj<=n; nj++){
                dp[0][mi][nj] = 1;
            }
        }

        for(int ind=1; ind<len; ind++){
            for(int mi=0; mi<=m; mi++){
                for(int nj=0; nj<=n; nj++){
                    int notPick =  dp[ind-1][mi][nj];
                    int pick = 0;

                    str = strs[ind];
                    cnt0 = count(str.begin(), str.end(), '0');
                    cnt1 = str.size() - cnt0;

                    if(cnt0 <= mi && cnt1 <= nj){
                        pick = 1 + dp[ind-1][mi-cnt0][nj-cnt1];
                    }

                    dp[ind][mi][nj] = max(notPick, pick);
                }
            }
        }

        return dp[len-1][m][n];
    }
};