class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        if(k == 1) return matrix[0][0];
        priority_queue <int > pq;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                pq.push(matrix[i][j]);
            }
            
        }
       while(pq.size() != k)
       {
           pq.pop();
       }
        return pq.top();
    }
};