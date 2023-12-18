class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
       // int ma1 = nums[0], ma2 = nums[1], mi1 = nums[2], mi2 = nums[3];
        sort(nums.begin(), nums.end());
        int first = nums[0]*nums[1];
        int sec = nums[nums.size()-1]*nums[nums.size()-2];
        
        return -( first - sec);
    }
};