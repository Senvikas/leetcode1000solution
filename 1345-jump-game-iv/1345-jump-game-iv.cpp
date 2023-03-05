class Solution 
{
public:
    int minJumps(vector<int>& arr) 
    {
        int n=arr.size();
        vector<int> adj[n];
        unordered_map<int,vector<int>> m;
        for(int x=0; x<n; x++) m[arr[x]].push_back(x);
        vector<int> vis(n,0);
        queue<int> q;
        q.push(0);
        vis[0]=1;
        int level=0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                int node=q.front();
                q.pop();
                if(node==n-1) return level;
                if(node+1==n-1) return 1+level;
                if(node-1>=0 && !vis[node-1]) 
                {
                    vis[node-1]=1;
                    q.push(node-1);
                }
                if(node+1<n && !vis[node+1]) 
                {
                    vis[node+1]=1;
                    q.push(node+1);
                }
                for(auto it: m[arr[node]])
                {
                    if(!vis[it]) 
                    {
                        if(it==n-1) return 1+level;
                        vis[it]=1;
                        q.push(it);
                    }
                }
                m[arr[node]].clear(); 
            }
            level++;
        }
        return n-1;
    }
};