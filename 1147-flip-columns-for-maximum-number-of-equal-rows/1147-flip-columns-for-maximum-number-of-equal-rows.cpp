class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(),  ans = 0;
        unordered_map<string, int> mp;

        for(auto &row: mat)
        {
            string patt = "", xorPatt = "";
            for(int ele: row)
            {
                if(ele == 0)
                {
                    patt.push_back('0');
                    xorPatt.push_back('1');
                }
                else{
                    xorPatt.push_back('0');
                    patt.push_back('1');
                }
            }

            if(mp.find(patt) != mp.end())
            {
                mp[patt]++;
            }
            else if(mp.find(xorPatt) != mp.end()){
                mp[xorPatt]++;
            }
            else{
                mp[patt]++;
            }
        }

        for(auto kv: mp)
        {
            ans = max(kv.second, ans);
        }
        return ans;
    }
};