class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        unordered_map<int,int>winners;
        unordered_map<int,int>loosers;

        for(int i=0; i<n; i++)
        {
            winners[matches[i][0]]++;
            loosers[matches[i][1]]++;
        }

       // cout<<loosers.count(6)<<endl;

        vector<vector<int>>ans;
        set<int>win;
        set<int>los;

        for(int i=0; i<n; i++)
        {
            if(loosers.find(matches[i][0]) == loosers.end())
            win.insert(matches[i][0]);
            if(loosers[(matches[i][1])] == 1)
            los.insert(matches[i][1]);
        }

        vector<int>w;
        for(auto &it : win)
            w.push_back(it);
        vector<int>l;
        for(auto &it : los)
            l.push_back(it);
        
        ans.push_back(w);
        ans.push_back(l);
        return ans;
    }
};