class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long ts = 0;
        for(int x: nums)
            ts += x;
        long long asc =   nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] < nums[i-1])
            {
                long long des = ts-asc+nums[i-1];
                // cout << asc << " " << des << endl;
                if(des == asc)
                    return -1;
                if(des > asc)
                    return 1;
                return 0;
            }
            asc += nums[i];
        }      
        return 2;
    }
};