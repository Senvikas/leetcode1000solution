class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n  = groupSizes.size();

        vector<vector<int>> temp (n+1);
        vector<vector<int>> res;

        for(int i=0;i<n;i++)
        {
            int len = groupSizes[i];

            temp[len].push_back(i);
            if(temp[len].size() == len)
            {
                res.push_back(temp[len]);
                 temp[len] = {};

            }
        }

        return res;
    }
};