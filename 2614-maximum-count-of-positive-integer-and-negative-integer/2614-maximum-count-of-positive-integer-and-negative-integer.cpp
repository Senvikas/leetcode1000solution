class Solution {
public:
    int maximumCount(vector<int>& arr) {
        int neg = 0, pos = 0;
        for(auto x: arr)
        {
            if(x < 0)neg++;
            else if(x > 0) pos++;
        }
        int ans = max(neg, pos);
        return ans;
    }
};