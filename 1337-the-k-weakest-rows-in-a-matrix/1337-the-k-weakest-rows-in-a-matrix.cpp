class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        vector<pair<int,int>> soldiers;
        
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=0; j<mat[i].size(); j++){
                if(mat[i][j]) cnt++;
            }
            soldiers.push_back({cnt, i});
            
        }
        sort(soldiers.begin(), soldiers.end());
        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(soldiers[i].second);
            
        }
        return ans;
    }
};