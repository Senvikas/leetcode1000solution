class Solution
{
    public:
        void dfs(vector<vector < int>> &arr, int x, int y, int n, int m, vector< int > &dx, vector< int > &dy, int st, int color)
        {
           	//    vis[x][y] = 1;
            for (int i = 0; i < 4; i++)
            {
                int newx = x + dx[i];
                int newy = y + dy[i];
                if (newx >= 0 && newy >= 0 && newx < n && newy < m && arr[newx][newy] != color && arr[newx][newy] == st)
                {
                    arr[newx][newy] = color;
                    dfs(arr, newx, newy, n, m, dx, dy, st, color);
                }
            }
        }
    vector<vector < int>> floodFill(vector<vector < int>> &image, int sr, int sc, int color)
    {
        int start = image[sr][sc];
        int n = image.size();
        int m = image[0].size();
       	//        vector<vector<int>>vis(n,vector < int>(m, 0));
        vector<int> dx = { -1, 0, 1, 0};
        vector<int> dy = { 0, 1, 0, -1};

        dfs(image, sr, sc, n, m, dx, dy, start, color);
        image[sr][sc] = color;
        return image;
    }
};