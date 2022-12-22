class Solution
{
    public:
        void dfs(int *vis, vector<int> adj[], int node)
        {
            vis[node] = 1;
            for (auto it: adj[node])
            {
                if (!vis[it])
                    dfs(vis, adj, it);
            }
        }

    int findCircleNum(vector<vector < int>> &isConnected)
    {
        int n = isConnected.size();
       	//to change adj matrix to adj list
        vector<int> adj[n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1 && i != j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int vis[201] = { 0 };
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                cnt++;
                dfs(vis, adj, i);
            }
        }
        return cnt;
    }
};