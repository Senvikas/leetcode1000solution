class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        
        vector<int> use = nums, curr;
        int cnt = n;
        while(cnt>1){
            cnt--;
            curr.resize(cnt);
            for(int i=0; i<cnt; i++){
                curr[i] = (use[i]+use[i+1])%10;
            }
            use = curr;
        }
        return use[0];
    }
};