//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
private:
    vector<int> topoSort(int n, vector<pair<int, int>> adj[]) {
        vector<int> indegree(n, 0);

        // Calculate in-degrees for each node
        for (int i = 0; i < n; i++) {
            for (auto it : adj[i]) {
                indegree[it.first]++;
            }
        }

        queue<int> q;

        // Initialize the queue with nodes having in-degree 0
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            // Reduce in-degree of adjacent nodes
            for (auto adjnode : adj[node]) {
                indegree[adjnode.first]--;

                // If in-degree becomes 0, add to the queue
                if (indegree[adjnode.first] == 0)
                    q.push(adjnode.first);
            }
        }

        return topo;
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[N];
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u].push_back({ v, wt });
        }

        vector<int> topo = topoSort(N, adj);
        vector<int> dist(N, 1e9); // Initialize with a large value
        dist[0] = 0; // Initialize the source node distance to 0

        // Bellman-Ford algorithm
        for (int i = 0; i < N; i++) {
            int node = topo[i];
            if (dist[node] == INT_MAX) continue; // Skip unreachable nodes
            for (auto adjnode : adj[node]) {
                int v = adjnode.first;
                int wt = adjnode.second;

                if (dist[node] + wt < dist[v])
                    dist[v] = dist[node] + wt;
            }
        }
        for (int i = 0; i < N; i++) {
        if (dist[i] == 1e9) dist[i] = -1;
      }
      return dist;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends