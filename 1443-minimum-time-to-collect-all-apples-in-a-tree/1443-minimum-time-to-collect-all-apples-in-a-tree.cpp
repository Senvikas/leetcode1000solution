class Solution
{
    public:
        int time = 0;
    bool helper(vector<vector < int>> &adj, vector< bool > &hasApple, int node, int parent)
    {
        bool apple = false;
        if (hasApple[node])
        {
            apple = true;
        }
        for (auto child: adj[node])
        {
            if (child != parent)
            {
                if (helper(adj, hasApple, child, node))
                {
                    apple = true;
                    time += 2;
                }
            }
        }

        return apple;
    }
    int minTime(int n, vector<vector < int>> &edges, vector< bool > &hasApple)
    {
        vector<vector < int>> adj(n);
        for (int i = 0; i < n - 1; i++)
        {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        helper(adj, hasApple, 0, -1);
        return time;
    }
};