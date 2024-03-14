class Solution {
public:
    int f(vector<int>& nums,int tar)
    {
        if(tar==-1) return 0;
        int l=0,r=0,res=0,sum=0;
        while(r<nums.size())
        {
            sum+=nums[r];
            while(sum>tar)
            {
                sum-=nums[l++];
            }
            res+=r-l+1;
            r++;
        }
        return res;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal)
    {
        return f(nums,goal)-f(nums,goal-1);
    }
};