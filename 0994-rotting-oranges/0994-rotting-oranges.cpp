#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>, int>> q;
        int n = grid.size();
        int m = grid[0].size(); // Corrected a typo: use grid[0].size() instead of grid.size()
        int cntFresh = 0;
        int cntRott = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1)
                    cntFresh++;
                else if(grid[i][j] == 2)
                {
                    cntRott++;
                    q.push({{i, j}, 0}); // Corrected a syntax error: added extra braces around {i, j}
                }
            }
        }
        if(cntFresh == 0) return 0;
        if(cntRott == 0) return -1;
        
        int delR[] = {-1, 0, 1, 0}; // Changed from int to int[]
        int delC[] = {0, -1, 0, 1}; // Changed from int to int[]
        
        vector<vector<int>> inputGrid = grid;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int minTime = 0; // Keep track of the minimum time required to rot all oranges
        
        while(!q.empty()){ // Corrected a typo: emptu() to empty()
            int qSize = q.size(); // Process all oranges at the current time level
            for(int k = 0; k < qSize; k++) {
                auto frontElem = q.front(); q.pop();
                int tm = frontElem.second;
                auto idxs = frontElem.first;
                int ro = idxs.first;
                int co = idxs.second;

                for(int i=0; i<4; i++){
                    int nr = ro + delR[i];
                    int nc = co + delC[i];

                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 1){
                        vis[nr][nc] = 1;
                        inputGrid[nr][nc] = 2;
                        q.push({{nr, nc}, tm+1});
                        cntFresh--;
                    } 
                }
            }
            if (!q.empty()) minTime++; // If there are oranges queued for the next minute, increment the time
        }
        
        return cntFresh == 0 ? minTime : -1;
    }
};
