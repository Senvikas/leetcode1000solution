class Solution {
public:
int dfs(int node,int n,vector<int> adj[],vector<bool> &vis)
{
    int res=1;
    vis[node]=true;
    for (int &child:adj[node])
    {
        if (vis[child]==false)
          res+=dfs(child,n,adj,vis);
    }
    return res;
}
bool isRange(vector<int> &v1,vector<int> &v2)
{

    int x=v1[0],y=v1[1],r=v1[2];
    int x2=v2[0],y2=v2[1];

    double dist=sqrt((x-x2)*(long long)(x-x2)+(y-y2)*(long long)(y-y2));
    return r>=dist;
}
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<int> adj[n];
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (i!=j)
                {
                    if (isRange(bombs[i],bombs[j]))
                      adj[i].push_back(j);
                }
            }
        }
        int maxi=1;
        
        for (int i=0;i<n;i++)
        {
            vector<bool> vis(n,false);
            maxi=max(maxi,dfs(i,n,adj,vis));
        }
        return maxi;
        
    }
};