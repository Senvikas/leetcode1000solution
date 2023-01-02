class Solution
{
    public:
        bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &path)
        {
            vis[node] = 1;
            path[node] = 1;

            for (auto it: adj[node])
            {
                if (!vis[it])
                {
                    if (dfs(it, adj, vis, path) == true) return true;
                }
                else if (path[it]) return true;
            }

            path[node] = 0;
            return false;
        }
   	// Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        vector<int> path(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, adj, vis, path) == true) return true;
            }
        }

        return false;
    }

    bool canFinish(int n, vector<vector < int>> &pr)
    {
        int len = pr.size();
        if (len <= 1) return true;
        vector<int> adj[n];

        for (int i = 0; i < len; i++)
        {
            int ind = pr[i][1];
            int val = pr[i][0];
            adj[ind].push_back(val);
        }

        for (int i = 0; i < n; i++)
        {
            bool ans = isCyclic(n, adj);
            cout << "ans is : " << ans << endl;
            if (ans) return false;
        }

        return true;
    }
};