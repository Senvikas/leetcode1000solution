class Solution {
public:
    
    //not working.
    int spaceOptWithThreeVars(vector<vector<int>> &mat) {
        int n = mat.size();
        int prevMin, currMin = INT_MAX; // Variables to track the minimum value
        for (int col = 0; col < n; col++)
            currMin = min(currMin, mat[n - 1][col]); // Initialize currMin with the last row's values

        for (int row = n - 2; row >= 0; row--) {
            prevMin = currMin; // Update prevMin for the next row
            currMin = INT_MAX; // Reset currMin for the next row
            for (int col = 0; col < n; col++) {
                int diaLeft = (col - 1 >= 0) ? mat[row][col] + prevMin : INT_MAX;
                int down = mat[row][col] + prevMin;
                int diaRight = (col + 1 < n) ? mat[row][col] + prevMin : INT_MAX;

                currMin = min(currMin, min(diaLeft, min(down, diaRight))); // Update currMin
            }
        }

        return currMin;
    }

    //not working.
    int spaceOptSingleVec(vector<vector<int>> &mat) {
        int n = mat.size();
        vector<int> dp(n, 0); // Single vector

        // Base case
        for (int col = 0; col < n; col++)
            dp[col] = mat[n - 1][col];

        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col < n; col++) {
                int diaLeft = (col - 1 >= 0) ? mat[row][col] + dp[col - 1] : INT_MAX;
                int down = mat[row][col] + dp[col];
                int diaRight = (col + 1 < n) ? mat[row][col] + dp[col + 1] : INT_MAX;

                dp[col] = min(diaLeft, min(down, diaRight));
            }
        }

        int ans = INT_MAX;
        for (int col = 0; col < n; col++)
            ans = min(ans, dp[col]);

        return ans;
    }

    
    
    
    int spaceOptWithTwoVec(vector<vector<int>> &mat){
        int n = mat.size();
        
        vector<int> next(n, 0);
        
        // Base case ->   if (row == n - 1) return mat[row][col];
        for(int col = 0; col < n; col++)
            next[col] = mat[n-1][col];
        
        for(int row=n-2; row>=0; row--){
             vector<int> curr(n, 0);
            for(int col=0; col<n; col++){
                
                int diaLeft = INT_MAX, down = INT_MAX, diaRight = INT_MAX;

                if (col - 1 >= 0) diaLeft = mat[row][col] + next[col - 1]; 
                down = mat[row][col] + next[col];
                if (col + 1 < n) diaRight = mat[row][col] + next[col + 1];

                curr[col] =  min(diaLeft, min(down, diaRight)); 
                 
            }
            next = curr;
        }
        int ans = INT_MAX;
        for(int col=0; col<n; col++) ans = min(ans, next[col]);
        
        return ans;
    }
    
    int tabulation(vector<vector<int>> &mat){
        int n = mat.size();
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Base case ->   if (row == n - 1) return mat[row][col];
        for(int col = 0; col < n; col++)
            dp[n-1][col] = mat[n-1][col];
        
        for(int row=n-2; row>=0; row--){
            for(int col=0; col<n; col++){
                
                int diaLeft = INT_MAX, down = INT_MAX, diaRight = INT_MAX;

                if (col - 1 >= 0) diaLeft = mat[row][col] + dp[row + 1][col - 1]; 
                down = mat[row][col] + dp[row + 1][col];
                if (col + 1 < n) diaRight = mat[row][col] + dp[row + 1][col + 1];

                dp[row][col] =  min(diaLeft, min(down, diaRight)); 
                 
            }
        }
        int ans = INT_MAX;
        for(int col=0; col<n; col++) ans = min(ans, dp[0][col]);
        
        return ans;
    }
    
    int solveRec(int row, int col, int n, vector<vector<int>> &mat, vector<vector<int>> &dp) {
        // Base case
        if (row == n - 1) return mat[row][col];

        if (row >= n || col < 0 || col >= n) return INT_MAX; 
        
        if(dp[row][col] != -1) return dp[row][col];   //2nd step

        int diaLeft = INT_MAX, down = INT_MAX, diaRight = INT_MAX;

        if (col - 1 >= 0) diaLeft = mat[row][col] + solveRec(row + 1, col - 1, n, mat, dp); 
        down = mat[row][col] + solveRec(row + 1, col, n, mat, dp);
        if (col + 1 < n) diaRight = mat[row][col] + solveRec(row + 1, col + 1, n, mat, dp);
        
        return dp[row][col] =  min(diaLeft, min(down, diaRight));     //1st step
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX; 
        
        vector<vector<int>> dp(n, vector<int>(n, -1));   //0th step
        /*
        for (int col = 0; col < n; col++) {
            ans = min(ans, solveRec(0, col, n, matrix, dp)); 
        }

        return ans;
        */
        return spaceOptWithTwoVec(matrix);
    }
};


