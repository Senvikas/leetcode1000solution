class Solution
{
    private:
        int timer = 1;	// variable to keep track of the current time
    void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], vector<int> &insertionTime, vector<int> &lowestTime, vector< vector< int>> &brides)
    {
        vis[node] = 1;	// mark the node as visited
        lowestTime[node] = insertionTime[node] = timer;	// set the insertion and lowest time of the node
        timer++;
        for (auto it: adj[node])	// iterate through all the neighboring nodes
        {
            if (it == parent) continue;	// skip the parent node
            if (vis[it] == 0)
            {
                dfs(it, node, vis, adj, insertionTime, lowestTime, brides);
                lowestTime[node] = min(lowestTime[node], lowestTime[it]);	// update the lowest time of the node

                if (lowestTime[it] > insertionTime[node])
                {
                   	brides.push_back({it, node});   // add the current edge as a bridge
                }
            }
            else
            {
                lowestTime[node] = min(lowestTime[node], lowestTime[it]);
            }
        }
        return;
    }
    public:
        vector<vector < int>> criticalConnections(int n, vector<vector < int>> &connections)
        {
            vector<int> adj[n];
            for (auto it: connections)
            {
                adj[it[0]].push_back(it[1]);	// add edges to the adjacency list
                adj[it[1]].push_back(it[0]);
            }

            vector<int> vis(n, 0), lowestTime(n), insertionTime(n);	// arrays for storing insertion and lowest time
            vector<vector < int>> brides;	// vector to store the bridges

            dfs(0, -1, vis, adj, insertionTime, lowestTime, brides);
            return brides;
        }
};