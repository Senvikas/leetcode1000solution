//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class DJS{
    public:
        vector<int>rank, parent, size;
        //constructor
        DJS(int n)
        {
            rank.resize(n+1, 0);
            parent.resize(n+1);
            size.resize(n+1, 1);
            for(int i=0; i<=n; i++)
                parent[i] = i;
        }

        //finding the ultimate parent of the node
        int findUltPar(int node)
        {
            if(node == parent[node]) return node;
            //otherwise call the function recursively
            return parent[node] = findUltPar(parent[node]);
        }

        void UnionByRank(int u, int v){
            int UP_u = findUltPar(u);
            int UP_v = findUltPar(v);
            if(UP_u == UP_v) return;

            if(rank[UP_u] < rank[UP_v])
            {
                parent[UP_u] = UP_v;
            }
            else if(rank[UP_v] < rank[UP_u])
            {
                parent[UP_v] = UP_u;
            }
            //else the rank is same and hence
            else{
                parent[UP_v] = UP_u;
                rank[UP_u]++;
            }
        }

        //UniouBySize
        void UnionBySize(int u, int v){
            int UP_u = findUltPar(u);
            int UP_v = findUltPar(v);
            if(UP_u == UP_v) return;

            if(size[UP_u] < size[UP_v])
            {
                parent[UP_u] = UP_v;
                size[UP_v] += size[UP_u];
            }
            else{
                parent[UP_v] = UP_u;
                size[UP_u] += size[UP_v];
            }
        }
};
class Solution {
  public:
  //creating self defined datatype for finding the unionByRank and uniouBySize

    int numProvinces(vector<vector<int>> adj, int V) {
        DJS ds(V);
        for(int i=0; i<V; i++)
        {
            for(int j=0; j<V; j++)
            {
                if(adj[i][j] == 1)
                {
                    ds.UnionBySize(i, j);
                }
            }
        }
        int cnt = 0;
        for(int i=0; i<V; i++)
        if(ds.parent[i] == i) cnt++;
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends