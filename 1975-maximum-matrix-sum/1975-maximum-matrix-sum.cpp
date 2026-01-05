class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long negCnt = 0, n = matrix.size(), smallest = 1e6, sum = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                smallest = min(smallest, (long long)abs(matrix[i][j]));
                sum += abs(matrix[i][j]);
                if(matrix[i][j] < 0)
                    negCnt++;
            }
        }
        
        if(negCnt%2 == 0)
            return sum;

        return sum - 2*smallest;
    }
};