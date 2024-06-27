class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(i < n-1 && nums[i] == 0){
                int j = i+1;
                while(j < n && nums[j] == 0) j++;
                if(j >= n) break;
                nums[i] = nums[j];
                nums[j] = 0;
            }
        }
        return ;
    }
};