//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int w, int wt[], int val[], int n, int ind, vector<vector<int>> &dp){
        if(ind == 0){
            if(wt[ind] <= w) return val[ind];
            return 0;
        }
        
        if(dp[ind][w] != -1) return dp[ind][w];
        
        //take
        int take = 0;
        if(w >= wt[ind]) take = val[ind] + solve(w-wt[ind], wt, val, n, ind-1, dp);
        
        int leave = solve(w, wt, val, n, ind-1, dp);
        
        return dp[ind][w] = max(take, leave);
        
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       //vector<vector<int>> dp(1001, vector<int>(1001, 0));
       //return solve(W, wt, val, n, n-1, dp);
       
       vector<int> prev(W+1, 0), curr(W+1, 0);
       for(int weight=wt[0]; weight<=W; weight++){
          prev[weight] = val[0];
       }
       
       //changing parmaerters are ind and weight
       for(int ind=1; ind<n; ind++){
           for(int weight=0; weight<=W; weight++){
                int take = 0;
                if(weight >= wt[ind]) take = val[ind] + prev[weight-wt[ind]];
                
                int leave = prev[weight];
                
                curr[weight] = max(take, leave);
           }
           prev = curr;
       }
       
       
       return prev[W];
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