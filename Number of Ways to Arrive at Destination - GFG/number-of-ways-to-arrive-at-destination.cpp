//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<int> ways(n, 0), dist(n, 1e10);
        ways[0] = 1; dist[0] = 0;
        
        int mod = (int)(1e9 + 7);
        
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
        pq.push({0, 0});
        
        vector<pair<int,int>> adj[n];
        for(auto it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        while(!pq.empty()){
            int node = pq.top().first;
            int cost = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int adjnode = it.first;
                int edgewt = it.second;
                
                //coming first time to this node with the shortest time.
                if(cost + edgewt < dist[adjnode]){
                    dist[adjnode] = cost + edgewt;
                    ways[adjnode] = ways[node];
                    pq.push({adjnode, cost+edgewt});
                }
                
                //have already came to this node with this shortest time.
                else if(cost + edgewt == dist[adjnode]){
                    ways[adjnode] =  ( ways[adjnode] + ways[node])%mod;
                }
            }
        }
        
        return ways[n-1]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends