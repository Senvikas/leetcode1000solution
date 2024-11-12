class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        sort(items.begin(), items.end(),
             [](vector<int> a, vector<int> b) { return a[0] < b[0]; });
        int size = items.size();
        // cout<<endl;
        int maximum = items[0][1];
        for (int i = 1; i < size; ++i) {
            if (items[i][1] > maximum) {
                maximum = items[i][1];
            }
            items[i][1] = maximum;
        }

        
        vector<int> ans = queries;
        sort(ans.begin(), ans.end());

        unordered_map<int, int> maps;

        int querySize = queries.size();
        int ind = 0;
        for (int i = 0; i < querySize; ++i) {
            if(ind<0) ind = 0 ; 
            while (ind < size && ans[i] >= items[ind][0]) {
            
                maps[ans[i]] = items[ind][1];
                ind++;
            }
            ind--;
            
        }

        for (int i = 0; i < querySize; ++i) {
            ans[i] = maps[queries[i]];
        }
        return ans;
    }
};