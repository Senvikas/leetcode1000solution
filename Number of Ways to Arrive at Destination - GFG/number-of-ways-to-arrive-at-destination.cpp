//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue< pair<int,int>, vector<pair<int,int>>,
        greater<pair<int,int>> >pq;
        pq.push({0, 0});
        
        vector<int>ways(n, 0), dist(n, 1e9);
        dist[0] = 0;
        ways[0] = 1;
        
        vector<pair<int,int>>adj[n];
        for(auto edge: roads)
        {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        int mod = (int)(1e9+7);
        while(!pq.empty())
        {
            auto it = pq.top(); pq.pop();
            int node = it.second;
            int dis = it.first;
            
            for(auto iter: adj[node])
            {
                int adjnode = iter.first;
                int edw = iter.second;
                
                if(dis + edw < dist[adjnode])
                {
                    ways[adjnode] = ways[node];
                    dist[adjnode] = dis + edw;
                    pq.push({dis+edw, adjnode});
                }
                else if(dis + edw == dist[adjnode])
                {
                    ways[adjnode] = (ways[adjnode] + ways[node])%mod;
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