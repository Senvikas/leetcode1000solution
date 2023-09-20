class Solution {
public: 
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for(int i = 0;i<nums.size();i++) sum+=nums[i];
        unordered_map<int, int> um; 
        sum = sum-x;
        int curr_sum = 0,maxLen = 0; 
        for(int i = 0;i<nums.size();i++){
          curr_sum+=nums[i];
          if (curr_sum == sum)
            maxLen = i + 1; 
          if (um.find(curr_sum) == um.end())
            um[curr_sum] = i;
          if (um.find(curr_sum - sum) != um.end()) {
            if (maxLen < (i - um[curr_sum - sum]))
                maxLen = i - um[curr_sum - sum];
           }
        } 
        if(maxLen == 0 && sum!=0) return -1;
        return nums.size()-maxLen;
      
    }
};