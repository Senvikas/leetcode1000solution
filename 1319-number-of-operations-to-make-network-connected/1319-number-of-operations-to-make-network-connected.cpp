    #include <bits/stdc++.h>
    using namespace std;

    //creating self defined datatype for finding the unionByRank and uniouBySize
    class DJS{

        public:
            vector<int>rank, parent, size;
            //constructor that initializes the data structures used in the class
            DJS(int n)
            {
                rank.resize(n+1, 0); //initializing the rank of all nodes to 0
                parent.resize(n+1); //initializing the parent of all nodes to itself
                size.resize(n+1, 1); //initializing the size of all nodes to 1
                for(int i=0; i<=n; i++)
                    parent[i] = i; //set the parent of all nodes to itself
            }

            //function to find the ultimate parent of a given node
            int findUltPar(int node)
            {
                if(node == parent[node]) return node; //if the node is its own parent, return it
                //otherwise call the function recursively to find the ultimate parent
                return parent[node] = findUltPar(parent[node]);
            }

            //function to merge two sets by rank
            void UnionByRank(int u, int v){
                int UP_u = findUltPar(u); //find the ultimate parent of node u
                int UP_v = findUltPar(v); //find the ultimate parent of node v
                if(UP_u == UP_v) return; //if they are already in the same set, return

                if(rank[UP_u] < rank[UP_v])
                {
                    parent[UP_u] = UP_v; //set the parent of UP_u as UP_v
                }
                else if(rank[UP_v] < rank[UP_u])
                {
                    parent[UP_v] = UP_u; //set the parent of UP_v as UP_u
                }
                //else the rank is same and hence
                else{
                    parent[UP_v] = UP_u; //set the parent of UP_v as UP_u
                    rank[UP_u]++; //increment the rank of UP_u
                }
            }

            //function to merge two sets by size
            void UnionBySize(int u, int v){
                int UP_u = findUltPar(u); //find the ultimate parent of node u
                int UP_v = findUltPar(v); //find the ultimate parent of node v
                if(UP_u == UP_v) return; //if they are already in the same set, return

                if(size[UP_u] < size[UP_v])
                {
                    parent[UP_u] = UP_v; //set the parent of UP_u as UP_v
                    size[UP_v] += size[UP_u]; //increment the size of UP_v by size of UP_u
                }
                else{
                    parent[UP_v] = UP_u; //set the parent of UP_v as UP_u
                    size[UP_u] += size[UP_v]; //increment the size of UP_u by size of UP_v
                }
            }
    };
    class Solution {
    public:
        int makeConnected(int n, vector<vector<int>>& connections) {
            DJS ds(n); //initialize the disjoint set data structure
            int cntExtras = 0; //variable to store the number of extra edges
            for(auto it: connections)
            {
                int u = it[0]; //get the first node of the edge
                int v = it[1]; //get the second node of the edge

                if(ds.findUltPar(u) == ds.findUltPar(v))
                    cntExtras++; //increment the count of extra edges if the nodes are already in the same set
                else{
                    ds.UnionBySize(u, v); //otherwise, merge the sets containing the nodes
                }
            }
            int connected_components = 0; //variable to store the number of connected components
            for(int i=0; i<n; i++)
            if(ds.parent[i] == i) connected_components++; //increment the count of connected components if the parent of the node is itself

            int ans = connected_components-1; //minimum number of edges to be removed = number of connected components -1
            if(ans <= cntExtras) return ans; //if the extra edges are more than or equal to the minimum number of edges to be removed
            return -1; //otherwise, it is not possible to make the graph connected
        }
    };

