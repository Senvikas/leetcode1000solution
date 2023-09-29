class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i+1 < n && nums[i] == nums[i+1]){
            i++;
        }
        if(i >= n-1) return true;
        int incOrDec = (int)(nums[i] < nums[i+1] ? 0 : 1);
        
        if(incOrDec){
            while(i+1<n){
                if(nums[i] < nums[i+1]) return false; i++;
            }
        }else{
            while(i+1<n){
                if(nums[i] > nums[i+1]) return false; i++;
            }
        }
        
        return true;
    }
};