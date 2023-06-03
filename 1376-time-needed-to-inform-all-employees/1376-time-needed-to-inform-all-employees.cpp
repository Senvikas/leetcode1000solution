class Solution {
    private:
    int dfs(std::vector<int>&informTime,std::unordered_map<int,std::vector<int>>&adjlist,int manager)
    {
        int maxtime=0;
        if(adjlist.find(manager)!=adjlist.end())
        {
            for(int subordinate:adjlist[manager])
            {
                maxtime=max(maxtime,dfs(informTime,adjlist,subordinate));
            }
        }
        return maxtime+informTime[manager];
    }
public:
  
    int numOfMinutes(int n, int headID, std::vector<int>& manager, std::vector<int>& informTime) {
        std::unordered_map<int,std::vector<int>> adjlist;
        for(auto i=0;i<n;i++)
        {
            if(manager[i]!=-1)
            {
                adjlist[manager[i]].push_back(i);
            }
        }
        return dfs(informTime,adjlist,headID);
    }
};