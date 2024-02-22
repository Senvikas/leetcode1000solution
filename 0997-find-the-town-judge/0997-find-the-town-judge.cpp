class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        set<int> st;
        for(int i=1; i<=n; i++) st.insert(i);
        
        for(auto it: trust){
            if(st.find(it[0]) != st.end()) st.erase(it[0]);
        }
        
        cout << st.size() << endl;
        if(st.size() != 1) return -1;
        int ans = (*st.begin());
        
        int believeCnt = 0;
        for(auto it: trust){
            if(it[1] == ans) believeCnt++;
        }
        if(believeCnt == n-1) return ans;
        return -1;
    }
};