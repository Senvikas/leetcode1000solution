class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);
        int cnt = 2*k + 1;
        if (n < cnt){
            return ans;
        }
        long long sum = 0;
        for(int i=0; i<2*k; i++){
            sum += nums[i];
        }
        for(int i=k; i+k<n; i++){
            sum += nums[i+k];
            ans[i] = sum/cnt;
            sum -= nums[i-k];
        }
        return ans;
    }
};