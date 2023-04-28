class Solution
{
    public:
       	
        bool isSimilar(string a, string b)
        {
            int diff = 0;	
            for (int i = 0; i < a.length(); i++)
            {
                if (a[i] != b[i]) diff++;
            }
            if (diff == 2 || diff == 0) return true;
            else return false;
        }
   
    void dfs(int i, vector<string> &strs, vector<int> &vis)
    {
        vis[i] = 1;
        for (int j = 0; j < strs.size(); j++)
        {
            if (!vis[j] && isSimilar(strs[i], strs[j]))
            {
            	//if jth string is the neighbour
                dfs(j, strs, vis);	//then we will check the neighbour of jth string that whether it is similar of not
            }
        }
    }
    int numSimilarGroups(vector<string> &strs)
    {
        int count = 0;	
        int n = strs.size();
        vector<int> vis(n, 0);	
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, strs, vis);
                count++;
            }
        }
        return count;
    }
};