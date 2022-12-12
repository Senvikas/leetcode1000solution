//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


int mod = 1e9+7;
class Solution{

	public:
	
	int solve(int arr[], int ind, int s, vector<vector<int>>&dp)
	{
	    //base cases
	  
	    if(ind == 0)
	    {
	        if(s == 0 && arr[0] == 0 )return 2;
	        if(s ==0 || arr[0] == s) return 1;
	        return 0;
	    }
	    
	    
	    if(dp[ind][s] != -1) return dp[ind][s];
	    
	    int exc = solve(arr, ind-1, s, dp);
	    int inc = 0;
	    if(s >= arr[ind]) inc = solve(arr, ind-1, s-arr[ind], dp);
	    
	    return dp[ind][s] = (inc+exc)%mod;
	    
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
	    
        vector<vector<int>>dp(n+1, vector<int>(sum+1, -1));
        return solve(arr, n-1, sum, dp)%mod;        
        
        
        
        /*
        vector<vector<int>>dp(n, vector<int>(sum+1, 0));
        for(int i=0; i<n; i++) dp[i][0] = 1;
        if(arr[0] < sum) dp[0][arr[0]] = 1;
        
        for(int ind=1; ind<n; ind++)
        {
            for(int s=1; s<=sum; s++)
            {
                int exc = dp[ind-1][s];
        	    int inc = 0;
        	    if(s >= arr[ind]) inc = dp[ind-1][s-arr[ind]];
        	    
        	    dp[ind][s] = inc + exc;
            }
        }
        
        return dp[n-1][sum];                       */
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends