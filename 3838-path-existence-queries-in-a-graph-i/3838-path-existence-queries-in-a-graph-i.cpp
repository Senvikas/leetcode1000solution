class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& qn) {
        vector<int> parent(n, 0);
        int group = 0;

        for(int i=1; i<n; i++)
        {
            int diff = nums[i] - nums[i-1];
            if(diff > maxDiff)
                group++;

            parent[i] = group;
        }

        vector<bool> ans;
        for(auto q: qn)
        {
            if(parent[q[0]] == parent[q[1]])
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};