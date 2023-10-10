class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
	    int n = grid[0].size();
	    vector<vector<int>> ans(m, vector<int>(n, 0));
	    vector<vector<int>> vis(m, vector<int>(n, 0));
	    vector<int> drow = {-1,0,1,0};
	    vector<int> dcol = {0,1,0,-1};
	    
	    queue<pair<pair<int,int>, int>>q;
	    for(int i=0; i<m; i++){
	        for(int j=0; j<n; j++){
	            if(grid[i][j] == 0) q.push({{i, j}, 0});
	        }
	    }
	    
	    while (!q.empty()) {
        auto frontNode = q.front();
        q.pop();
        auto cords = frontNode.first;
        auto dist = frontNode.second;
    
        int x = cords.first, y = cords.second;
    
        for (int i = 0; i < 4; i++) {
            int nx = x + drow[i];
            int ny = y + dcol[i];
    
            // Check if (nx, ny) is valid and update distances
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && vis[nx][ny] == 0 && grid[nx][ny] == 1) {
                
                ans[nx][ny] = dist+1;
                vis[nx][ny] = 1;
                q.push({{nx, ny}, dist+1});
            }
        }
    }

	    return ans;
    }
};