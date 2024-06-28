class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]] = i;
        }
        
        for(int i=0; i<n; i++){
            int req = target - nums[i];
            if(mp.find(req) != mp.end() && mp[req] != i) return {mp[req], i};
        }
        
        
        return {-1, -1};
    }
};