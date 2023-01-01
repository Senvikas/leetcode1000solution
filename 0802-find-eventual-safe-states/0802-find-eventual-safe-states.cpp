class Solution
{
    public:
        bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &path, vector< int > &check)
        {
            vis[node] = 1;
            path[node] = 1;

           	//traverse all the adjacent nodes
            for (auto it: adj[node])
            {
                if (!vis[it])
                {
                    if (dfs(it, adj, vis, path, check) == true)
                    {
                        check[node] = 0;
                        return true;
                    }
                }
                else if (path[it]) return true;
            }

            check[node] = 1;
            path[node] = 0;
            return false;
        }

    vector<int> eventualSafeNodes(vector<vector < int>> &g)
    {
        int n = g.size();
        vector<int> vis(n, 0);
        vector<int> check(n, 0);
        vector<int> path(n, 0);
        vector<int> adj[n];

        for (int i = 0; i < n; i++)
        {
            vector<int> v = g[i];
            for (auto it: v)
            {
                adj[i].push_back(it);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, path, check);
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (check[i]) ans.push_back(i);
        }
        return ans;
    }
};