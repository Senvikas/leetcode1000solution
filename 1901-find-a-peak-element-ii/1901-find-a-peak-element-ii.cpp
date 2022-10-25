// class Solution {
//     int index_of_maxele_inRow(vector<int> &arr, int m){
//         int maxi = 0;
//         int index = 0;
//         for(int i=0; i<m; i++)
//         {
//             if(arr[i] > maxi){
//                 maxi = arr[i];
//                 index = i;
//             }
//         }
//         return index;
//     }
    
// public:
//     vector<int> findPeakGrid(vector<vector<int>>& mat) {
//        //algo 1. srow, erow 2.mrow 3. max element find krna middrow m 4. pahli and last to 5. nii to 6. if iska ulta to 7. nii to 
//         int n=mat.size();
//         int m=mat[0].size();
        
//         int s=0, e=mat.size()-1;
//         while(s <= e)
//         {
//             int mid = s + (e-s)/2;
            
//             int maxrowindex = index_of_maxele_inRow(mat[mid], mat[mid].size());
            
//             if((mid == 0 || mat[mid][maxrowindex] > mat[mid-1][maxrowindex]) && (mid == n-1 || mat[mid][maxrowindex] > mat[mid+1][maxrowindex]))
//                 return {mid, maxrowindex};
//             else if(m>0 &&  mat[mid][maxrowindex] < mat[mid-1][maxrowindex])
//                 s = mid+1;
//             else
//                 e = mid-1;
//         }
//         return {-1, -1};
//     }
// };

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), lo = 0, hi = m - 1, mid; 
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            int max_row = 0;
            for (int i = 0; i < n; ++i) {
                if (matrix[max_row][mid] < matrix[i][mid])
                    max_row = i;
            }
            if ((mid == 0 || matrix[max_row][mid] > matrix[max_row][mid - 1]) && 
                (mid == m - 1 || matrix[max_row][mid] > matrix[max_row][mid + 1]))
                return {max_row, mid};
            else if (mid > 0 && matrix[max_row][mid - 1] > matrix[max_row][mid])
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return {-1, -1};
    }
};