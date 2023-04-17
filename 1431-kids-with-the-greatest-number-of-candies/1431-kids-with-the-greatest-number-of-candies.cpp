class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        vector<bool> ans;
        int mx = INT_MIN;
        for(auto &i : candies)
            mx = max(mx, i);

        for(auto &i : candies)
            ans.push_back(i + extraCandies >= mx);

        return ans;
    }
};