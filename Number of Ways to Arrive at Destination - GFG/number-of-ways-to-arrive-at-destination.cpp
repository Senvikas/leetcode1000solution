//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int num_of_city, vector<vector<int>>& roads) {
    // Create a priority queue to store the time and node
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
    
    // Push the starting node with time 0
    pq.push({0, 0});

    // Declare a vector 'num_of_ways' to store the number of ways to reach each node
    vector<int>num_of_ways(num_of_city, 0);
    
    // Declare a vector 'min_time' to store the minimum time to reach each node
    vector<int>min_time(num_of_city, 1e9);
    
    // Set the initial time to 0
    min_time[0] = 0;
    
    // Set the initial number of ways to 1
    num_of_ways[0] = 1;

    // Declare a vector of pairs 'adj' to store the adjacent nodes and their time
    vector<pair<int,int>>adj[num_of_city];
    
    // Store the roads in the adjacency list
    for(auto edge: roads)
    {
        adj[edge[0]].push_back({edge[1], edge[2]});
        adj[edge[1]].push_back({edge[0], edge[2]});
    }
    
    // Declare a variable 'mod_value' to store the mod value
    int mod_value = (int)(1e9+7);
    
    // Perform Dijkstra's algorithm
    while(!pq.empty())
    {
        // Get the front of the priority queue
        auto it = pq.top(); pq.pop();
        
        // Get the node
        int node = it.second;
        
        // Get the time
        int time = it.first;

        // Iterate through the adjacent nodes
        for(auto iter: adj[node])
        {
            // Get the adjacent node
            int adjnode = iter.first;
            
            // Get the time
            int time_to_adjnode = iter.second;

            // If the new time is less than the current minimum time to reach the adjacent node
            if(time + time_to_adjnode < min_time[adjnode])
            {
                // Update the number of ways to reach the adjacent node
                num_of_ways[adjnode] = num_of_ways[node];
                
                // Update the minimum time
                min_time[adjnode] = time + time_to_adjnode;
                
                // Push the adjacent node and new time to the priority queue
                pq.push({time+time_to_adjnode, adjnode});
            }
            // If the new time is equal to the current minimum time to reach the adjacent node
            else if(time + time_to_adjnode == min_time[adjnode])
            {
                // Update the number of ways to reach the adjacent node
                num_of_ways[adjnode] = (num_of_ways[adjnode]+num_of_ways[node])%mod_value;

                }
            }
        }
        return num_of_ways[num_of_city-1]%mod_value;
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