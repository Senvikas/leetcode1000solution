class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
       map<vector<int>,int> mp;

       int res=0;

       int row=grid.size();
       int col=grid[0].size();

       for(int i=0;i<row;i++){
           mp[grid[i]]++;
       }

       for(int i=0;i<col;i++){

           vector<int> temp;

           for(int j=0;j<row;j++){
               temp.push_back(grid[j][i]);
           }

           res+=mp[temp];
       }
    
    return res;
    }
};