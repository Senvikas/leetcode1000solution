class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int s = 0; int e = n-1;
        int maxwater = 0;
        while(s<e)
        {
            maxwater = max(maxwater, min(height[s], height[e])*(e-s));
            height[s] < height[e] ? s++ : e--;
        }
        return maxwater;
    }
};