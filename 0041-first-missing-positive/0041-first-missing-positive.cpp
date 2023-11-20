class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int positiveIndex = 0;
        
        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                swap(nums[i], nums[positiveIndex]);
                positiveIndex++;
            }
        }
        
        for(int i=0; i<positiveIndex; i++){
            int index = abs(nums[i]) - 1;
            if(index < positiveIndex){
                nums[index] = -abs(nums[index]);
            }
        }
        
        int ans = 1;
        for (; ans <= positiveIndex; ++ans) {
            if (nums[ans - 1] > 0) {
                break;
            }
        }

        return ans;
    }
};