//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
                         
        if(grid[destination.first][destination.second] == 0) return -1;
        
        queue< pair<int, pair<int,int>>>q;
        q.push({0, source});
        int delR[4] = {-1, 0, 1, 0};
        int delC[4] = {0, 1, 0, -1};
        
        int n = grid.size();
        int m = grid[0].size();
        
        int dist[n][m];
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                dist[i][j] = 1e9;
        
        dist[source.first][source.second] = 0;       
        while(!q.empty()){
            auto frontNode = q.front();
            q.pop();
            int dis = frontNode.first;
            auto cords = frontNode.second;
            int xcord = cords.first;
            int ycord = cords.second;
            
            if(cords == destination) return dis;
            
            for(int i=0; i<4; i++){
                int nx = xcord + delR[i];
                int ny = ycord + delC[i];
                
                if(nx >= 0 && nx < n && ny >= 0 && ny < m
                    && grid[nx][ny] == 1){
                        if(dis + 1 < dist[nx][ny]){
                            dist[nx][ny] = dis+1;
                            q.push({dis+1, {nx, ny}});
                        }
                    }
                    
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends