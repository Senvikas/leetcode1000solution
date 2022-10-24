class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> previousSums;
        int count = 0, sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            
            if(sum == k) count++;
            
            int previousSum = sum - k;
            if(previousSums.find(previousSum) != previousSums.end())
                count += previousSums[previousSum];
            
            previousSums[sum]++;
        }
        return count;
    }
};