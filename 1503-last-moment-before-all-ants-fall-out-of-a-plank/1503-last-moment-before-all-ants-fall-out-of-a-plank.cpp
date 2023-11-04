class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int minRight=INT_MAX;
        int maxLeft=INT_MIN;
        for(auto x:left)
        {
            maxLeft=max(maxLeft,x);
        }
        for(auto x:right)
        {
            minRight=min(minRight,x);
        }
        return max(maxLeft,n-minRight);
    }
};