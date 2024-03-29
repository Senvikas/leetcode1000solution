//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

bool f(vector<int>arr, int s, int ind, vector<vector<int>>&dp)
{
    if(s==0) return 1;
    if(ind == 0) return s==arr[0];
    if(dp[ind][s] != -1) return dp[ind][s];
    bool exc = f(arr, s, ind-1, dp);
    
    bool inc = false;
    if(arr[ind] <= s) 
    inc = f(arr, s-arr[ind], ind-1, dp);
    
    return dp[ind][s] = (inc || exc);
}

    bool isSubsetSum(vector<int>arr, int sum){
     /*   vector<vector<int>>dp(101, vector<int>(100001, -1));
        return f(arr, sum, arr.size()-1, dp);       */
        int n=arr.size();
        vector<bool>prev(sum+1, false), curr(sum+1, false);
        prev[0] = true; curr[0] = true;
        prev[arr[0]] = true;
        
        for(int i=1; i<n; i++)
        {
            for(int tar=1; tar<=sum; tar++)
            {
                bool exc = prev[tar];
    
                bool inc = false;
                if(arr[i] <= tar) 
                inc = prev[tar-arr[i]];
                
                curr[tar] = inc | exc;
            }
            prev = curr;
        }
        return prev[sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends