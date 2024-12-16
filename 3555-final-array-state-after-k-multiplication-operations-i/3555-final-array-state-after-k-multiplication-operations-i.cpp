class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multi) {
        while(k--)
        {
            int ind = -1;
            int mini = 1e9;

            for(int i=0; i<nums.size(); i++)
            {
                if(mini > nums[i])
                {
                    ind = i;
                    mini = nums[i];
                }
            }

            nums[ind] *= multi;
        }


        return nums;
    }
};