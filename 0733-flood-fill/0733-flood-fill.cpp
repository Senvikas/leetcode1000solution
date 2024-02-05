using pii = pair<int,int>;
class Solution {
public:
    
    //To check if the new cords are well withing the ranged of grid.
    bool valid(int i, int j, vector<vector<int>> &grid){
        int m = grid.size(), n = grid[0].size();
        if(i>=0 && i<m && j>=0 && j<n) return true;
        return false;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldCol = image[sr][sc];
        int m = image.size(), n = image[0].size();
        
        //Don't temper the given data, store in other grid and change in that one.
        vector<vector<int>> clone = image;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        //To move to adjacent cords
        vector<int>dx = {1, 0, 0, -1};
        vector<int>dy = {0, -1, 1, 0};
        
        int cnt = 0;
        queue<pii> q;
        q.push({sr, sc});
        vis[sr][sc] = 1;
        
        while(!q.empty()){
            //Need to process all the elements of q at once.
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                auto frontNode = q.front();
                q.pop();
                
                int sr = frontNode.first, sc = frontNode.second;
                
                //If current cell has an old col
                if(clone[sr][sc] == oldCol){
                    clone[sr][sc] = color;
                    cnt++;

                    for(int move=0; move<4; move++){
                        //Finding adjacent cords to the current cords
                        int srn = sr + dx[move];
                        int scn = sc + dy[move];
                        
                        //Cords are valid and Not visited previously and having old color then store them to process next.
                        if(valid(srn, scn, clone) && !vis[srn][scn] && clone[srn][scn] == oldCol){
                            q.push({srn, scn});
                            vis[srn][scn] = 1;
                        }
                    }
                
                }
            }
        }
        //cout << "Number of Pixels that changed to new Colors: " << cnt << endl;
        return clone;
    }
};