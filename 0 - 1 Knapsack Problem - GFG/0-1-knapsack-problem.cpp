//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    int solveMem(int *weight, int* value, int index, 
    int capacity, vector< vector<int> > &dp) // TLE
{
    if(index == 0)
    {
        if(weight[index] <= capacity) return value[0];
        else return 0;
    }
    if(dp[index][capacity] != -1) return dp[index][capacity];
    //incl
    int incl = 0;
    if(weight[index] <= capacity)
        incl = value[index] + solveMem(weight, value, index-1, 
                                      capacity-weight[index], dp);
    //excl
    int excl = 0 + solveMem(weight, value, index-1, capacity, dp);
    return dp[index][capacity] = max(incl, excl);

}
    
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
     /*  vector< vector<int> > dp(n, vector<int>(W+1, -1));
    return solveMem(wt, val, n-1, W, dp);           */
    
    
    /*
     vector< vector<int> > dp(n, vector<int>(W+1, 0));
     
    //basecase
    for(int i=wt[0]; i<=W; i++) dp[0][i] = val[0];
    
    for(int i=1; i<n; i++)
    {
        for(int wei=0; wei<=W; wei++)
        {
            int incl = 0;
            if(wt[i] <= wei)
                incl = val[i] + dp[i-1][wei - wt[i]];
            //excl
            int excl = 0 + dp[i-1][wei];
            
            //update
            dp[i][wei] = max(incl, excl);
        }
    }
        
        return dp[n-1][W];                         */
        
        vector<int>prev(W+1, 0), curr(W+1, 0);
        for(int i=wt[0]; i<=W; i++) prev[i] = val[0];
        
    for(int i=1; i<n; i++)
        {
            for(int wei=0; wei<=W; wei++)
            {
                int incl = 0;
                if(wt[i] <= wei)
                    incl = val[i] + prev[wei - wt[i]];
                //excl
                int excl = 0 + prev[wei];
                
                //update
                curr[wei] = max(incl, excl);
            }
            prev = curr;
        }
    
    return prev[W];                 
    
    //single row optimization
    
    //  vector<int>prev(W+1, 0);
    //   for(int i=wt[0]; i<=W; i++) prev[i] = val[0];
      
    //      for(int i=1; i<n; i++)
    //         {
    //             for(int wei = W; wei>=0; wei--)
    //             {
    //                 int incl = 0;
    //                 if(wt[i] <= wei)
    //                     incl = val[i] + prev[wei - wt[i]];
    //                 //excl
    //                 int excl = 0 + prev[wei];
                    
    //                 //update
    //                 prev[wei] = max(incl, excl);
    //             }
    //         }
    //     return prev[W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends