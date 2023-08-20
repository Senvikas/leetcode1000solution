class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int n = nums.size();
        
        for(int i=1; i<n; i++){
            if(nums[i-1] == nums[i]){
                nums[i-1] = 101;
            }
        }
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            if(nums[i] > 100) break;
            k++;
        }
        return k;
    }
};