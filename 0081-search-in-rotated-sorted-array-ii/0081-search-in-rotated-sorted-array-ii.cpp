class Solution {
public:
    bool search(vector<int>& nums, int target) {
        auto ans = find(nums.begin() , nums.end() , target);

        if(ans!= nums.end())
        {
            return true;
        }
        else
        return false;
    }
};