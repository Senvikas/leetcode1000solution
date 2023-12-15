class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        string k = paths[0][1];
        for(int i = 1 ; i<paths.size() ; i++)
        {
            for(int j = 0; j<paths.size(); j++)
            {
                if(paths[j][0] == k)
                {
                    k = paths[j][1];
                }
            }
        }
        return k;
    }
};