class Solution {
public:
    void dfs(int st, vector<int> &ans, set<int> &s, unordered_map<int, vector<int>> &mp){
        if(s.find(st) != s.end()) return;
        s.insert(st);
        ans.push_back(st);
        for(auto adj:mp[st])dfs(adj, ans, s, mp);
        return ;
    }
    vector<int> restoreArray(vector<vector<int>>& ap) {
        
        unordered_map<int, vector<int>> mp;
        for(auto a : ap){
            mp[a[0]].push_back(a[1]);
            mp[a[1]].push_back(a[0]);
        }
        
        int st = 0;
        for(auto a:mp){
            if(a.second.size() == 1) st = a.first;
        }
        
        vector<int> ans;
        set<int> s;
        
        dfs(st, ans, s, mp);
        return ans;
        
    }
};