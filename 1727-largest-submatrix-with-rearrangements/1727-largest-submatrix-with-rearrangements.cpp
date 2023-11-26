class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int area=0;
        int row=matrix.size(),col=matrix[0].size();
        for(int j=0;j<col;j++){
            int cntOnes=0;
            for(int i=0;i<row;i++){
                if(matrix[i][j]){
                    cntOnes++;
                    matrix[i][j]=cntOnes;
                }else{
                    cntOnes=0;
                }
            }
        }
        for(int i=0;i<row;i++){
            map<int,int> m;
            for(int j=0;j<col;j++){
                if(matrix[i][j])
                    m[-matrix[i][j]]++;
            }
            int prev=0;
            for(auto it : m){
                prev+=it.second;
                area=max(area,prev*it.first*-1);
            }
        }
        return area;
    }
};