//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n, 1e9);
        dist[src] = 0;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}}); // stops, {node, cost}

        while (!q.empty()) {
            auto frontNode = q.front();
            q.pop();
            int stops = frontNode.first;
            int node = frontNode.second.first;
            int cost = frontNode.second.second;

            if (stops > K) {
                continue;
            }

            for (auto adjNodePair : adj[node]) {
                int adjNode = adjNodePair.first;
                int edgeWt = adjNodePair.second;

                if (cost + edgeWt < dist[adjNode]) {
                    dist[adjNode] = cost + edgeWt;
                    q.push({stops + 1, {adjNode, cost + edgeWt}});
                }
            }
        }

        return (dist[dst] == 1e9) ? -1 : dist[dst];
    }
};




//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends