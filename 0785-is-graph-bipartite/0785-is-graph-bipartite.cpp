class Solution
{
    public:
        int color[105];
    int vis[105];

    bool dfs(vector<vector < int>> &graph, int i, int col)
    {
        vis[i] = 1;
        color[i] = col;

        for (auto adj: graph[i])
        {
            if (vis[adj] == 0)
            {
                if (dfs(graph, adj, col ^ 1) == false) return false;
            }
            else
            {
                if (color[i] == color[adj]) return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector < int>> &graph)
    {
        int n = graph.size();

        for (int i = 0; i < n; i++)
        {
            if (color[i] == 0 && (dfs(graph, i, 0) == false)) return false;
        }

        return true;
    }
};