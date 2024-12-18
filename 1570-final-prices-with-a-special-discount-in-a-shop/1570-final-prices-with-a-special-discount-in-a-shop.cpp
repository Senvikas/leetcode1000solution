class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans = prices;
        int n = prices.size();

        vector<int> inds;

        for(int i=0; i<n; i++)
        {
            int curr = prices[i];
            while(!inds.empty() && prices[inds.back()] >= curr)
            {
                ans[inds.back()] -= curr;
                inds.pop_back();
            }

            inds.push_back(i);
        }

        return ans;
    }
};