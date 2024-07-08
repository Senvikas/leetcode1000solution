class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int n = mat.size(), m = mat[0].size();
        
        int r = n-1, c = 0;
        
        while(r>=0 && c<m){
            if(mat[r][c] == t) return true;
            else if(mat[r][c] > t) r--;
            else c++;
        }
        
        return false;
    }
};