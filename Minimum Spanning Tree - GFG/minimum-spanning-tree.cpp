//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DJS{
    private:
        vector<int>rank, parent, size;
    public:
        //constructor
        DJS(int n)
        {
            rank.resize(n+1, 0);
            parent.resize(n+1);
            size.resize(n+1, 1);
            for(int i=0; i<=n; i++)
                parent[i] = i;
        }

        //finding the ultimate parent of the node
        int findUltPar(int node)
        {
            if(node == parent[node]) return node;
            //otherwise call the function recursively
            return parent[node] = findUltPar(parent[node]);
        }

        void UnionByRank(int u, int v){
            int UP_u = findUltPar(u);
            int UP_v = findUltPar(v);
            if(UP_u == UP_v) return;

            if(rank[UP_u] < rank[UP_v])
            {
                parent[UP_u] = UP_v;
            }
            else if(rank[UP_v] < rank[UP_u])
            {
                parent[UP_v] = UP_u;
            }
            //else the rank is same and hence
            else{
                parent[UP_v] = UP_u;
                rank[UP_u]++;
            }
        }

        //UniouBySize
        void UnionBySize(int u, int v){
            int UP_u = findUltPar(u);
            int UP_v = findUltPar(v);
            if(UP_u == UP_v) return;

            if(size[UP_u] < size[UP_v])
            {
                parent[UP_u] = UP_v;
                size[UP_v] += size[UP_u];
            }
            else{
                parent[UP_v] = UP_u;
                size[UP_u] += size[UP_v];
            }
        }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector< pair<int, pair<int,int>>>edges;
        for(int node = 0; node < V; node++)
        {
            for(auto it: adj[node])
            {
                int adjnode = it[0];
                int wt = it[1];
                
                edges.push_back({wt, {node, adjnode}});
            }
        }
        
        DJS ds(V);
        sort(edges.begin(), edges.end());
        int mstwt = 0;
        
        for(auto it: edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findUltPar(u) != ds.findUltPar(v))
            {
                mstwt += wt;
                ds.UnionBySize(u, v);
            }
        }
        return mstwt;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends