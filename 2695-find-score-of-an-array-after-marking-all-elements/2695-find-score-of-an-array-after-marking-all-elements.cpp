class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<pair<int,int>> valInd;
        int n = nums.size();

        long long score = 0;

        for(int i=0; i<n; i++)
        {
            valInd.push_back({nums[i], i});
        }

        sort(valInd.begin(), valInd.end());

        vector<int> marked(n, 0);

        for(int i=0; i<n; i++)
        {
            pair<int,int> p = valInd[i];
            int val = p.first;
            int ind = p.second;

            if(marked[ind] == 1)
                continue;

            score += val;

            if(ind > 0) marked[ind-1] = 1; 
            marked[ind] = 1;
            if(ind < n-1) marked[ind+1] = 1;
        }

        return score;
    }
};