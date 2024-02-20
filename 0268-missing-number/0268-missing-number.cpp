class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int n = nums.size();
        long long int sum = 0;
        for(auto it:nums){
            sum += it;
        }

        return (n*(n+1))/2 - sum;  
    }
};