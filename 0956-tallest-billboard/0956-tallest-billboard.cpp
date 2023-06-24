class Solution
{
public:
    int tallestBillboard(vector<int> &rods)
    {
        unordered_map<int, pair<int, int>> dpMap;
        dpMap[0] = {0, 0};
        for (int i = 0; i < rods.size(); i++)
        {
            unordered_map<int,pair<int,int>> copyDp = dpMap;
            for (auto x : dpMap)
            {
                int v1 = x.second.first;int v2 = x.second.second;
                vector<pair<int,int>> possiblePairs = {{v1+rods[i],v2},{v1,v2+rods[i]},{v1,v2}};
                for(pair<int,int> y:possiblePairs){
                    int diff = abs(y.first-y.second);
                    int maxVal = max(y.first,y.second);
                    if(copyDp.find(diff)!=copyDp.end()){
                        if(maxVal>copyDp[diff].second){
                            copyDp[diff] = {(maxVal-diff),maxVal};
                        }
                    }else{
                        copyDp[diff] = {(maxVal-diff),maxVal};
                    }
                }
            }
            dpMap = copyDp;
        }
        return dpMap[0].second;
    }
};