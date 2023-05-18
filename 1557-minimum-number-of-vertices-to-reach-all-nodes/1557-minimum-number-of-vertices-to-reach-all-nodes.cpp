class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        set<int> st;
        for(int i=0; i<n; i++) st.insert(i);
        for(auto e: edges)st.erase(e[1]);
        int sz = st.size();
        vector<int> ans;
        for(auto s: st) ans.push_back(s);
        return ans;
    }
};