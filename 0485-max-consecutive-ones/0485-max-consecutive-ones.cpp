class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0, sum = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0) sum = 0;
            else sum++;
            maxi = max(maxi, sum);
        }
        
        return maxi;
    }
};