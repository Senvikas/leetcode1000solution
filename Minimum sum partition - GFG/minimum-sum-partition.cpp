//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int totsum = 0;
	    for(auto i=0; i<n; i++) totsum += arr[i];
	    
	    int sum = totsum;
	    
	    
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
        
        //cout<<prev[0] <<" " <<prev[1] << " " <<prev[7]<<endl;
        int mini = INT_MAX;
        for(int i=0; i<=sum; i++)
        {
            if(prev[i])
            {
                mini = min(mini, abs(totsum - 2*i));
            }
        }
        return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends