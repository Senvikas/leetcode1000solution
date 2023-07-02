class Solution {
public:
    int ans=0;
    void solve(int idx,int cnt,int n,vector<vector<int>>&requests,vector<int>&indegree){
        if(idx==requests.size()){
            for(int i=0;i<n;i++){
                if(indegree[i]){
                    return;
                }
            }
            ans=max(ans,cnt);
            return;
        }
        //pick the request
        indegree[requests[idx][0]]--;
        indegree[requests[idx][1]]++;
        solve(idx+1,cnt+1,n,requests,indegree);
        //not pick the request
        indegree[requests[idx][0]]++;
        indegree[requests[idx][1]]--;
        solve(idx+1,cnt,n,requests,indegree);
        return;

    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int>indegree(n,0);
        solve(0,0,n,requests,indegree);
        return ans;
    }
};