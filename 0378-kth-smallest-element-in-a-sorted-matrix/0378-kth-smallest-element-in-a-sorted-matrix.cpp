/*
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
                if(pq.size() > k)
                    pq.pop();

            }
            
        }
     return pq.top();
    }
};

*/
    
    class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int midval;
        int startval = matrix[0][0];
        int endval = matrix[m-1][n-1];
        
        while(startval <= endval)
        {
            midval = startval + (endval - startval)/2;
            int smallcount = 0;
            for(int i=0; i<m; i++)
            {
                //binary search on each row
                int low = 0;
                int high = n-1;
                int mid;
                
                while(low<=high)
                {
                    mid = low + (high - low)/2;
                    if(matrix[i][mid] <= midval) low = mid+1;
                    else high = mid-1;
                }
                smallcount += low;
            }
            if(smallcount < k) startval = midval+1;
            else endval = midval - 1; 
        }
        return startval;
    }
};
