class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        set<int> st; vector<int>beleive_cnt(n+1, 0);
        for(int i=1; i<=n; i++) st.insert(i);
        for(auto it: trust)
        {
            int val = it[0];
            if(st.find(val) != st.end()) st.erase(val);
            beleive_cnt[it[1]]++;
        }
        cout << st.size() << endl;
        if(st.size() != 1) return -1;
        int ans = 0;
        for(auto i: st) ans = i;
        if(beleive_cnt[ans] == n-1)
        return ans;
        return -1;
    }
};