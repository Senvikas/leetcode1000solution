class Solution {
public:
    int rev(int num) {
        std::string numStr = std::to_string(num);
        std::reverse(numStr.begin(), numStr.end());
        return std::stoi(numStr);
    }

    int countNicePairs(std::vector<int>& nums) {
        std::unordered_map<int, int> mp;
        int n = nums.size();
        int mod = 1e9 + 7;
        long long ans = 0; 

        for (int i = 0; i < n; i++) {
            int diff = nums[i] - rev(nums[i]);
            ans = (ans + mp[diff]) % mod; 
            mp[diff]++;
        }

        return int(ans);
    }
};


