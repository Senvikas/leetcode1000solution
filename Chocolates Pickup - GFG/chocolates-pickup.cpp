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
        vector<vector<vector<int> > > dp(n, vector<vector<int>>(m, vector<int>(m, 0)));           
        //return f(n, m, grid, 0, 0, m-1, dp);
    /*      //memo
        //filling up the last 2d vec
        for(int j1=0; j1<m; j1++)
        {
            for(int j2=0; j2<m; j2++)
            {
                if(j1 == j2)
                dp[n-1][j1][j2] = grid[n-1][j1];
                else
                dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }

        //filling up further from 1 - n
        for(int i=n-2; i>=0; i--)
        {
            for(int j1=0; j1<m; j1++)
            {
                for(int j2=0; j2<m; j2++)
                {
                    int m_c = 0;
                  for(int dj1=-1; dj1<2; dj1++)
                  {
                      for(int dj2=-1; dj2<2; dj2++)
                      {
                          int choc = 0;
                          if(j1==j2) 
                            choc = grid[i][j1];
                          else
                            choc = grid[i][j1] + grid[i][j2];
                            
                        if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m )
                        choc += dp[i+1][j1+dj1][j2+dj2];
                        else
                        choc += -1e7;
                        m_c = max(m_c, choc);
                      }
                  }
                  dp[i][j1][j2] = m_c;
                }
            }
        }
        return dp[0][0][m-1];
        */
        //further space optimization
        vector<vector<int>>front(m, vector<int>(m, 0)), curr(m, vector<int>(m, 0));
        //filling up the last 2d vec
        for(int j1=0; j1<m; j1++)
        {
            for(int j2=0; j2<m; j2++)
            {
                if(j1 == j2)
                front[j1][j2] = grid[n-1][j1];
                else
                front[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }

        //filling up further from 1 - n
        for(int i=n-2; i>=0; i--)
        {
            for(int j1=0; j1<m; j1++)
            {
                for(int j2=0; j2<m; j2++)
                {
                    int m_c = 0;
                  for(int dj1=-1; dj1<2; dj1++)
                  {
                      for(int dj2=-1; dj2<2; dj2++)
                      {
                          int choc = 0;
                          if(j1==j2) 
                            choc = grid[i][j1];
                          else
                            choc = grid[i][j1] + grid[i][j2];
                            
                        if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m )
                        choc += front[j1+dj1][j2+dj2];
                        else
                        choc += -1e7;
                        m_c = max(m_c, choc);
                      }
                  }
                  curr[j1][j2] = m_c;
                }
            }
            front = curr;
        }
        return front[0][m-1];
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