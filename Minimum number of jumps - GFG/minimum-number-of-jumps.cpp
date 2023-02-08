//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        int mr = 0, cr = 0, jump = 0;
        for(int i=0; i<=n-2; i++)
        {
            mr = max(mr, arr[i]+i);
            if(arr[i] <= 0 && mr <= i) return -1; 
            if(i == cr)
            {
                cr = mr;
                jump++;
            }
        }
        return jump;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends