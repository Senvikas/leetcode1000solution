//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends











class Solution {
public:
    bool bfs(int i, vector<int>& vis, vector<int> adj[]) {
        vis[i] = 1;
        queue<pair<int, int>> q;
        q.push({i, -1});

        while (!q.empty()) {
            auto front = q.front();
            int node = front.first;
            int parent = front.second;

            for (auto adjnode : adj[node]) {
                if (!vis[adjnode]) {
                    vis[adjnode] = 1;
                    q.push({adjnode, node});
                } else if (parent != adjnode) {
                    return true;
                }
            }

            q.pop(); // Remove the explored node from the queue.
        }

        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (bfs(i, vis, adj)) return true;
            }
        }

        return false;
    }
};









//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends