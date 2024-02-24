class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int, vector<pair<int,int>>> adj ; 

        // create adjacency List
        for (auto ele: meetings) {
            adj[ele[0]].push_back({ele[1], ele[2]}) ; 
            adj[ele[1]].push_back({ele[0], ele[2]}) ; 
        }

        // use BFS traversal but to ensure that the person who know the secret first spread it before the one who knew late.

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> > pq ; // { time, person}
        vector<int> vis(n, 0) ; // track if they already know or not

        pq.push({0, 0}) ; 
        pq.push({0, firstPerson}) ; // firstPerson is the one who first knew the secret


        // visited for priority queue se nikalne se pehle hi vis kar dene se agar usko kam time me 
        // pta chalna hoga tab bhi nhi chalega, agar koi choti value aayi to bhi wo use push nhi karega.
        // vis[0] = vis[firstPerson] = 1 ; (ye nhi karna)

        while(!pq.empty()) {
            
            // pick the person who knew first 
            pair<int,int> frontNode = pq.top() ; 
            pq.pop() ; 

            int person = frontNode.second ; 
            int time = frontNode.first ; 

            if (vis[person]) {
                continue ;
            }

            vis[person] = true;
            for (auto neighbour: adj[person]) {
                int newNode = neighbour.first ; 
                int newTime = neighbour.second ;

                if (!vis[newNode]) {
                    if (newTime >= time) {
                        // vis[newNode] = 1 ; (ye wrong hai)
                        pq.push({newTime, newNode}) ;
                    }
                }
            }
            
        }

        vector<int> ans ;
        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                ans.push_back(i);
            }
        }

        return ans ; 
    }
};