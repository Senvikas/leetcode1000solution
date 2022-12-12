//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int mod = 1e9+7;
class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        int t = 0;
        for(auto &i: arr) t+=i;
        if(t-d <0 || (t-d)&1) return 0;
        int sum = (t-d)/2;
        
        vector<vector<int>>dp(n, vector<int>(sum+1, 0));
        if(arr[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;
        
        if(arr[0] != 0 && arr[0] <= sum) dp[0][arr[0]] = 1;
        for(int i=1; i<n; i++)
        {
            for(int s=0; s<=sum; s++)
            {
                int exc = dp[i-1][s];
                int inc = 0;
                if(s>=arr[i]) inc = dp[i-1][s-arr[i]];
                
                dp[i][s] = (inc + exc)%mod;
            }
        }
        return dp[n-1][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends