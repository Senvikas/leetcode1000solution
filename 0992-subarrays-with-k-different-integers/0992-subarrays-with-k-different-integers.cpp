class Solution
{
    int max_possible_up_till(vector<int> &nums, int k)
    {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int cnt = 0;
        map<int, int> mp;
        while (j < n)
        {
            mp[nums[j]]++;
            while (mp.size() > k)
            {
                auto it = mp.find(nums[i]);
                it->second--;
                if (it->second == 0) mp.erase(it);
                i++;
            }
            cnt += j - i + 1;
            j++;
        }
        return cnt;
    }

    public:
        int subarraysWithKDistinct(vector<int> &nums, int k)
        {
           	//k=3 exactly means-max_possible_up_till 3 - max_possible_up_till 2
            return max_possible_up_till(nums, k) - max_possible_up_till(nums, k - 1);
        }
};