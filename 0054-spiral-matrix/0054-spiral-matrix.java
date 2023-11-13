class Solution {
    public List<Integer> spiralOrder(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;
        
        int srow=0, scol=0, lrow=n-1, lcol=m-1;
        int cnt = 0;
        List<Integer> ans = new ArrayList<>();
        while(cnt < m*n){
            //if(cnt > m*n) break;
            //first row -> traverse on columns
            for(int j=scol; j<=lcol; j++){
                ans.add(mat[srow][j]);
                cnt++;
            }
            srow++; // 1
            if(cnt >= m*n) break;
            //last col -> t........ on rows
            for(int i=srow; i<=lrow; i++){
                ans.add(mat[i][lcol]);
                cnt++;
            }
            lcol--;   // 3
            if(cnt >= m*n) break;
            //last row
            for(int j=lcol; j>=scol; j--){
                ans.add(mat[lrow][j]);
                cnt++;
            }
            lrow--;  // 3
            if(cnt >= m*n) break;
            //first col
            for(int i=lrow; i>=srow; i--){
                ans.add(mat[i][scol]);
                cnt++; 
            }
            scol++;  // 1
            if(cnt >= m*n) break;
        }
        
        return ans;
    }
}