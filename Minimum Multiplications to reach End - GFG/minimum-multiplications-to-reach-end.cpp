//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        
        queue<pair<int,int>> q;
        q.push({start, 0});
        
        vector<int> dist(100000, 1e9);
        int mod = 100000;
        dist[start] = 0;
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            int steps = it.second;
            int num = it.first;
            
            for(auto numb : arr){
                int multi = (numb * num)%mod;
                if(steps + 1 < dist[multi]){
                    if(multi == end) return steps+1;
                    dist[multi] = steps+1;
                    q.push({multi, steps+1});
                }
            }
        }
        if(dist[end] == 1e9) return -1;
        return dist[end];
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends