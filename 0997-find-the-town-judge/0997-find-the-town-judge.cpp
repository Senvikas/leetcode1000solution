class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n+1, 0), outdegree(n+1, 0);
        for(auto it: trust){
            indegree[it[1]]++;
            outdegree[it[0]]++;
        }
        
        
        int anss = 0;
        
        for(int i=1; i<=n; i++){
            if(indegree[i] == n-1){
                if(anss != 0) return -1;
                anss = i;
            }
        }
        
        if(outdegree[anss] != 0) return -1;
        //return anss;
        
        if(anss == 0) return -1;
        return anss;
        /*
        set<int> st;
        for(int i=1; i<=n; i++) st.insert(i);
        
        for(auto it: trust){
            if(st.find(it[0]) != st.end()) st.erase(it[0]);
        }
        
        if(st.size() != 1) return -1;
        int ans = (*st.begin());
        
        int believeCnt = 0;
        for(auto it: trust){
            if(it[1] == ans) believeCnt++;
        }
        if(believeCnt == n-1) return ans;
        return -1;
        */
    }
};