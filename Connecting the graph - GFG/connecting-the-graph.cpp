//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
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
    int Solve(int n, vector<vector<int>>& edge) {
        DJS ds(n);
        int cntExtras = 0;
        for(auto it: edge)
        {
            int u = it[0];
            int v = it[1];
            
            if(ds.findUltPar(u) == ds.findUltPar(v))
                cntExtras++;
            else
                ds.UnionBySize(u, v);
        }
        int cntC = 0;
        for(int i=0; i<n; i++)
            if(ds.parent[i] == i) cntC++;
        
        int ans = cntC-1;
        if(ans <= cntExtras) return ans;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends