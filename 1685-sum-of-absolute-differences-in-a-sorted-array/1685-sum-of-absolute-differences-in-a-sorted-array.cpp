class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int si=nums.size();
        vector<int>out(si,0);
        for(int i=1;i<si;i++)
        {
            nums[i]+=nums[i-1];
        }
        out[0]=abs((nums[si-1]-nums[0])-(si-1)*nums[0]);
        for(int i=1;i<si;i++)
        {
            int rl=si-(i+1);
            int ll=i;
            int mr=rl*(nums[i]-nums[i-1]);
            int ml=ll*(nums[i]-nums[i-1]);
            out[i]=abs((nums[si-1]-nums[i])-mr)+abs(nums[i-1]-ml);
        }
        return out;
    }
};