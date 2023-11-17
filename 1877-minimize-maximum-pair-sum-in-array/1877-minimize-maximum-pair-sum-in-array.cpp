class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
		int ans = 0;
        int i=0, j=nums.end() - nums.begin() -1;
        while(i < j){
            ans = max(ans, nums[j] + nums[i]);
            i++; j--;
        }
        return ans;
    }
};