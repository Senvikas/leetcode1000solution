class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0,sum=nums[0],ans=INT_MAX;
        bool flag = false;
        while(j<nums.size()){
            if(sum == target){
                ans = min(ans,j-i+1);
                flag = true;
                if(j+1 < nums.size()){
                    sum+=nums[j+1];
                }
                j++;
            }
            else if(sum>target){
                ans = min(ans,j-i+1);
                flag = true;
                if(i<j ){
                    sum-=nums[i];
                    i++;
                }
                else{
                    if(j+1 < nums.size()){
                        sum+=nums[j+1];
                    }
                    j++;
                }
            }
            else{
                if(j+1 < nums.size()){
                    sum+=nums[j+1];
                }
                j++;
            }
        }
        if(flag == false){
            return 0;
        }
        return ans;
    }
};