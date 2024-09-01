class Solution {
public:
    int f(vector<int> nums, int k){
        if(k<0) return 0;

        int right = 0, left = 0, sum = 0, n = nums.size(), ans = 0;

        while(right < n){
            sum += nums[right]%2;

            while(sum > k){
                
                sum -= nums[left]%2;
                left++;
            }
            ans += right - left + 1;
            right++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k-1);
    }
};