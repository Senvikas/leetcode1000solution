class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        priority_queue<pair<int, int>> pq; // Min-heap
        
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=0; j<mat[i].size(); j++){
                if(mat[i][j]) cnt++;
            }
            pq.push({cnt, i});
            if(pq.size() > k) pq.pop();
        }
        
        vector<int> ans;
        while(!pq.empty()){
            ans.insert(ans.begin(), pq.top().second); // Insert at the beginning to maintain order
            pq.pop();
        }
        return ans;
    }
};