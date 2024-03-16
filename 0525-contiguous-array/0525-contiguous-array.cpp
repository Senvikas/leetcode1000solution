class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum=0,length=0, n=nums.size();
        unordered_map<int,int> prefix;
        for(int i=0;i<n;i++){
            sum+=(nums[i]==0)?-1:1;
            if(sum==0) length=i+1;
            else if(prefix.find(sum)!=prefix.end()) length=max(length,i-prefix[sum]);
            else prefix[sum]=i;
        }
        return length;
    }
};