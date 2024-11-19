class Solution {
public:
    using ll = long long;
    long long maximumSubarraySum(vector<int>& nums, int k) {
        ll ans = 0;
        int l = 0, r = 0, n = nums.size();
        ll sum = 0;

        unordered_map<int,int> mp;
        while(r < n)
        {
            int curr = nums[r];
            sum += curr;
            mp[curr]++;

            // if we've at least k elements ---> r - l + 1 = k
            while(r - l + 1 == k)
            {
                if(mp.size() == k)
                {
                    ans = max(ans, sum);
                }

                // shrink the window
                int prev = nums[l];
                if(mp[prev] == 1)
                {
                    mp.erase(prev);
                }
                else
                {
                    mp[prev]--;
                }

                sum -= prev;
                l++;
            }
            r++;
        }

        return ans;
    }
};