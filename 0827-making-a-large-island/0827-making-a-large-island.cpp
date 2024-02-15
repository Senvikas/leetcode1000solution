/*gfg*/
#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 


class Solution {
    bool isValid(int x, int y, int n){
        return x>=0 && x<n && y>=0 && y<n;
    }
  public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        // Create a disjoint set to represent connected components
        DisjointSet* ds = new DisjointSet(n*n);
        
        // Define movement directions
        int dr[] = {1, 0, 0, -1};
        int dc[] = {0, -1, 1, 0};
        
        // Union adjacent cells with value 1
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0) continue;
                
                for(int k=0; k<4; k++){
                    int adjr = i + dr[k];
                    int adjc = j + dc[k];
                    
                    // If adjacent cell is valid and contains 1
                    if(isValid(adjr, adjc, n) && grid[adjr][adjc] == 1){
                        
                        // Calculate node and adjacent node
                        int node = i*n + j;
                        int adjNode = adjr*n + adjc;
                        
                        // Union the two cells by size
                        ds->unionBySize(node, adjNode);
                    }
                }
            }
        }
        
        int ans = 0;
        
        // Traverse through cells with value 0
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1) continue;
                set<int> components;
                
                // Check adjacent cells
                for(int k=0; k<4; k++){
                    int newr = i + dr[k];
                    int newc = j + dc[k];
                    
                    if(isValid(newr, newc, n)){
                        if(grid[newr][newc] == 1){
                            int cell = newr*n + newc;
                            components.insert(ds->findUPar(cell));
                        }
                    }
                }
                
                // Calculate the size of connected components
                int sizeByThisCell = 0;
                for(auto it: components){
                    sizeByThisCell += ds->size[it];
                }
                
                // Update the maximum connected component size
                ans = max(ans, sizeByThisCell + 1);
            }
        }
        
        // Find the size of the largest connected component in the grid
        for(int i=0; i<n*n; i++){
            ans = max(ans, ds->size[ds->findUPar(i)]);
        }
        
        return ans;
    }
};

/*
int main(){
    vector<vector<int>> grid = {{1,1},{1,0}}

    Solution soln;
    int ans = soln.largestIsland(grid);

    cout << "After changing any one 0 to 1, the maximum size of one component can be: " << ans << endl;
    return 0;
}
*/