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
        
        vector<int>prev(sum+1, 0), curr(sum+1, 0);
        if(arr[0] == 0) prev[0] = 2;
        else prev[0] = 1;
        
        if(arr[0] != 0 && arr[0] <= sum) prev[arr[0]] = 1;
        for(int i=1; i<n; i++)
        {
            for(int s=0; s<=sum; s++)
            {
                int exc = prev[s];
                int inc = 0;
                if(s>=arr[i]) inc = prev[s-arr[i]];
                
                curr[s] = (inc + exc)%mod;
            }
            prev = curr;
        }
        return prev[sum];
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