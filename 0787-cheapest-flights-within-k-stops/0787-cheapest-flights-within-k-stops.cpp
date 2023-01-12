class Solution {
public:
int findCheapestPrice(int num_of_city, vector<vector<int>>& flights, int src, int dst, int max_stops) {
    // Declare a vector 'min_cost_to_reach' to store the minimum cost to reach each node
    vector<int>min_cost_to_reach(num_of_city, 1e9);
    // Declare a queue 'q' to store the current node, number of stops and cost
    queue<pair<int, pair<int,int>>>q;
    // Push the initial source node, 0 stops and 0 cost
    q.push({0, {src, 0}});
    // Declare a vector of pairs 'adj' to store the adjacent nodes and their edge weight
    vector<pair<int,int>>adj[num_of_city];
    // Store the flights in the adjacency list
    for(auto e: flights)
    {
        adj[e[0]].push_back({e[1], e[2]});
    }
    // Perform BFS
    while(!q.empty())
    {
        // Get the front of the queue
        auto it = q.front(); q.pop();
        // Get the number of stops
        int stops = it.first;
        // Get the node
        int node = it.second.first;
        // Get the cost
        int cost = it.second.second;
        
        // If the number of stops exceeds max_stops, continue to the next iteration
        if(stops > max_stops) continue;
        // Iterate through the adjacent nodes
        for(auto iter: adj[node])
        {
            // Get the adjacent node
            int adjnode = iter.first;
            // Get the edge weight
            int edge_weight = iter.second;
            // If the new cost is less than the current minimum cost to reach the adjacent node
            if(cost + edge_weight < min_cost_to_reach[adjnode])
            {
                // Update the minimum cost
                min_cost_to_reach[adjnode] = cost + edge_weight;
                // Push the adjacent node, number of stops+1 and new cost to the queue
                q.push({stops+1, {adjnode, cost+edge_weight}});
            }
        }
    }
    // If the minimum cost to reach the destination is still the maximum value, return -1
    if(min_cost_to_reach[dst] == 1e9) return -1;
    // Otherwise, return the minimum cost to reach the destination
    return min_cost_to_reach[dst];
}

};