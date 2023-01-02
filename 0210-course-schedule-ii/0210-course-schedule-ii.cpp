class Solution
{
    public:
        vector<int> findOrder(int n, vector<vector < int>> &pr)
        {
            int len = pr.size();
            vector<int> adj[n];

            for (int i = 0; i < len; i++)
            {
                int ind = pr[i][1];
                int val = pr[i][0];
                adj[ind].push_back(val);
            }

            vector<int> indegree(n, 0);
            for (int i = 0; i < n; i++)
            {
                for (auto it: adj[i])
                {
                    indegree[it]++;
                }
            }

            queue<int> q;
            for (int i = 0; i < n; i++)
            {
                if (indegree[i] == 0) q.push(i);
            }

            vector<int> topoSorted;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                topoSorted.push_back(node);
                for (auto it: adj[node])
                {
                    indegree[it]--;
                    if (indegree[it] == 0) q.push(it);
                }
            }

            bool ans = topoSorted.size() == n;
            if (ans) return topoSorted;
            return {};
        }
};