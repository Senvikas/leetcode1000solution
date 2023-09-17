//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        
        int n = heights.size();
    int m = heights[0].size();

    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[0][0] = 0;

    int delR[4] = {-1, 0, 1, 0};
    int delC[4] = {0, 1, 0, -1};

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, 0}});

    while (!pq.empty()) {
        auto frontNode = pq.top();
        pq.pop();

        int dis = frontNode.first;
        int x = frontNode.second.first;
        int y = frontNode.second.second;

        if (x == n - 1 && y == m - 1) return dis;

        for (int i = 0; i < 4; i++) {
            int xc = x + delR[i];
            int yc = y + delC[i];

            if (xc >= 0 && xc < n && yc >= 0 && yc < m) {
                int absdiff = abs(heights[xc][yc] - heights[x][y]);

                int maxDiff = max(absdiff, dist[x][y]);

                if (maxDiff < dist[xc][yc]) {
                    dist[xc][yc] = maxDiff;
                    pq.push({maxDiff, {xc, yc}});
                }
            }
        }
    }
    return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends