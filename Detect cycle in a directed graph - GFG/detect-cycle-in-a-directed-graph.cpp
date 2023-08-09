//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfsCheck(int node, int vis[], int pathVis[], vector<int> adj[]){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto adjnode : adj[node]){
            if(!vis[adjnode]){
                if(dfsCheck(adjnode, vis, pathVis, adj)) return true;
            }else if(pathVis[adjnode]) return true;
        }
        
        
        pathVis[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int pathVis[V] = {0};
        
        for(int i=0; i<V; i++){
            if(!vis[i])
            {
                if(dfsCheck(i, vis, pathVis, adj)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends