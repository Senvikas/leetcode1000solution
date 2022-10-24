class Solution
{
    public:
        vector<vector < int>> merge(vector<vector < int>> &intervals)
        {
            vector<vector < int>> ans;
            int n = intervals.size();
            sort(intervals.begin(), intervals.end());
            vector<int> curr = intervals[0];
            for (int i = 1; i < n; i++)
            {
               	//no overlap
                if (curr[1] < intervals[i][0])
                {
                    ans.push_back(curr);
                    curr = intervals[i];
                }
                else
                {
                    curr[1] = max(curr[1], intervals[i][1]);
                }
            }
            ans.push_back(curr);
            return ans;
        }
};

//[[1,13], [2,5], [6,9], [10,12], [12,15], [18,22], [23,25]]