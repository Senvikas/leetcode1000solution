class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0;
        int l = 0, r = 0, n = nums.size();
        unordered_map<int,int> mp; // val ---> freq;

        while(r < n)
        {
            mp[nums[r]]++;

            int maxi = INT_MIN;
            int mini = INT_MAX;

            for(auto &[val, freq]: mp)
            {
                maxi = max(val, maxi);
                mini = min(val, mini);
            }

            while(maxi - mini > 2)
            {
                mp[nums[l]]--;
                if(mp[nums[l]] == 0)
                {
                    mp.erase(nums[l]);
                }
                l++;

                maxi = INT_MIN;
                mini = INT_MAX;
                for(auto &[val, freq]: mp)
                {
                    maxi = max(val, maxi);
                    mini = min(val, mini);
                }
            }


            ans += (r - l + 1);
            r++;
        }

        return ans;
    }
};