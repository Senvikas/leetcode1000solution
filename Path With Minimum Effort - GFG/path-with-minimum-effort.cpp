//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        int n= heights.size(), m = heights[0].size();
        vector<vector<int>>dist(n, vector<int>(m, 1e9));
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        pq.push({0, {0, 0}});
        while(!pq.empty())
        {
            auto it = pq.top(); pq.pop();
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            if(r == n-1 && c == m-1) return diff;
            for(int i=0; i<4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr >=0 && nr < n && nc >=0 && nc <m)
                {
                    int effort = abs(heights[nr][nc] - heights[r][c]);
                    int newdiff = max(effort, diff);
                    if(newdiff < dist[nr][nc])
                    {
                       dist[nr][nc] = newdiff;
                       pq.push({newdiff, {nr, nc}});
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends