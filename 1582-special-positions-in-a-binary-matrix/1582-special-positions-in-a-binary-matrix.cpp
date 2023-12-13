class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> row(n), col(m);
        
        //traver col wise
        for(int j=0; j<m; j++){
            int cnt = 0;
            for(int i=0; i<n; i++){
                if(mat[i][j] == 1) cnt++;
            }
            col[j] = cnt;
        }
        
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=0; j<m; j++){
                if(mat[i][j] == 1) cnt++;
            }
            row[i] = cnt;
        }
        int cnt = 0;
        for(int j=0; j<m; j++){
            for(int i=0; i<n; i++){
                if(mat[i][j] == 1) {
                    if(row[i] == 1 && col[j] == 1)
                        cnt++;
                }
            }
            
        }
     return cnt;   
    }
};