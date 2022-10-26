/* Naive solution O(N*N)
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            int sum = 0;
            for(int j=i+1; j<n; j++)
            {
                sum += nums[j];
                if(sum%k == 0) return true;
            }
        }
        return false;
    }
};
*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        nums[0] = nums[0]%k;
        for(int i=1; i<n; i++){
            nums[i] = (nums[i-1] + nums[i]%k)%k;
        }
        map<int,int> mp;
        mp[nums[0]] = 0;
        for(int i=1; i<n; i++)
        {
            if(nums[i] == 0) return 1;
            
            else if(mp.find((nums[i]-k+k)%k)!=mp.end()){
                if(i-mp[(nums[i]-k+k)%k]>1)
                return 1;
            }
            
            else if(mp.find(nums[i])==mp.end())
            mp.insert({nums[i],i});
        }
        
        return false;
    }
};