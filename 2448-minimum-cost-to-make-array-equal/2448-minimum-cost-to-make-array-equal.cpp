class Solution {
private:
    // f(x) => convex function (refer figure)
    long long f(vector<int> &nums, vector<int> &cost, int base) {
        // calc the total cost for making every element equal to base
        long long int res = 0;
        for (int i=0; i<nums.size(); i++) {
            res+= 1L*abs(nums[i] - base)*cost[i];
        }
        return res; 
    }
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        //initialize ans to be equal to the cost of making each element equal to nums[0]
        long long int ans = f(nums, cost, nums[0]);
        //since we know that the range of the convex funtion is [min(nums), max(nums)]
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());
        while (l<r) {
            int mid = (l+r)/2;
            // x => x; x_1 => x+1
            long long int x = f(nums, cost, mid);
            long long int x_1 = f(nums, cost, mid+1);
            ans = min(x, x_1);
            if (x > x_1) l = mid+1;
            else r = mid;
        }
        return ans;
        
    }
};