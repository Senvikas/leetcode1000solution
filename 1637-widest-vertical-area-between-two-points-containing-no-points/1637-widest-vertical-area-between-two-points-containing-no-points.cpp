class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int dis=0;
        map<long long int,int>mp;
        for(int i=0;i<points.size();i++){
            mp[points[i][0]]++;
        }

          for (auto it = mp.begin(); next(it) != mp.end(); ++it) {
           if(dis< next(it)->first - it->first){
               dis=next(it)->first - it->first;
           } 
    }
        return dis;
    }
};
