class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();

        int total = 0 , i = 0 , j = m-1;
        while(i < n && j >= 0){
            if(grid[i][j] < 0){
                total += (n - i);
                j--;
            }
            else i++;
        }   
        return total;
    }
};