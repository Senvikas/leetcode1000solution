//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
     int lcs (string s, string t, int n, int m)
        {
            vector<vector < int>> dp(n + 1, vector<int> (m + 1, 0));
            int ans = 0;
                 for (int i = 1; i <= n; i++)
                 {
                     for (int j = 1; j <= m; j++)
                     {
                         if (s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                         else dp[i][j] = 0;
                         ans = max(ans, dp[i][j]);
                     }
                 }
                 return ans;
            }
    
    
    int longestCommonSubstr (string s, string t, int n, int m)
    {
        return lcs(s, t, n, m);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends