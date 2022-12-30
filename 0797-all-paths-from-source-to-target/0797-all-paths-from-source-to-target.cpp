class Solution
{
    public:
        void dfs(vector<vector < int>> &ans, vector< int > path, int i, int n, vector< vector< int>> &g)
        {
            if (i >= n - 1)
            {
                path.push_back(i);
                ans.push_back(path);
                path.clear();
                return;
            }
            path.push_back(i);
            vector<int> v = g[i];
            for (auto j: v)
            {
                dfs(ans, path, j, n, g);
            }
            path.pop_back();
            return;
        }

    vector<vector < int>> allPathsSourceTarget(vector<vector < int>> &graph)
    {
        vector<vector < int>> ans;
        vector<int> path;
        int n = graph.size();
        dfs(ans, path, 0, n, graph);
        return ans;
    }
};