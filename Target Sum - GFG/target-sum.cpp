//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
  int countPartitions(int n, int d, vector<int> &arr)  //refer to dp 18.
        {
            int t = 0;
            for (auto &i: arr) t += i;
            if (t - d < 0 || (t - d) &1) return 0;
            int sum = (t - d) / 2;

            vector<int> prev(sum + 1, 0), curr(sum + 1, 0);
            if (arr[0] == 0) prev[0] = 2;
            else prev[0] = 1;

            if (arr[0] != 0 && arr[0] <= sum) prev[arr[0]] = 1;
            for (int i = 1; i < n; i++)
            {
                for (int s = 0; s <= sum; s++)
                {
                    int exc = prev[s];
                    int inc = 0;
                    if (s >= arr[i]) inc = prev[s - arr[i]];

                    curr[s] = (inc + exc) ;
                }
                prev = curr;
            }
            return prev[sum];
        }

    int solve(vector<int> &arr, int t, int i, vector<vector< int>> &dp)
    {
        if (i < 0) return t == 0;
        if (dp[i][2000 + t] != -1) return dp[i][2000 + t];
        int sub = solve(arr, t - arr[i], i - 1, dp);
        int add = solve(arr, t + arr[i], i - 1, dp);

        return dp[i][2000 + t] = add + sub;
    }

    int findTargetSumWays(vector<int> &arr, int target)
    {
        int n = arr.size();
        /*      vector<vector<int>>dp(n+1, vector < int>(4001, -1));
               return solve(arr, target, arr.size()-1, dp);          */

        return countPartitions(n, target, arr );
    }
  
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends