//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
  
  int f(int n, int m, vector<vector<int>>& g, int i, int j1, int j2,vector<vector<vector<int> > >&dp)
  {
      //base cases
      if(j1<0 || j1>=m || j2<0 || j2>=m) return -1e7;
      if(i==n-1)
      {
          if(j1==j2) return g[i][j1];
          else return g[i][j1] + g[i][j2];
      }
      if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
      int m_c = 0;
      for(int dj1=-1; dj1<2; dj1++)
      {
          for(int dj2=-1; dj2<2; dj2++)
          {
              if(j1==j2) 
              m_c = max(m_c, g[i][j1] + f(n, m, g, i+1, j1+dj1, j2+dj2, dp)) ;
              else
              m_c = max(m_c, g[i][j1] + g[i][j2] + f(n, m, g, i+1, j1+dj1, j2+dj2, dp));
          }
      }
      
      return dp[i][j1][j2] = m_c;
  }
  
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int> > > dp(n, vector<vector<int>>(m, vector<int>(m, -1)));           
        return f(n, m, grid, 0, 0, m-1, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends