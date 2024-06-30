class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        int n = nums.size();
        int s = 0, e = n-1;
        
        while(s <= e){
            int mid = s + (e-s)/2;
            
            if(nums[mid] == target){
                int m = mid;
                while(m-1 >= 0 && nums[m-1] == target) m--;
                ans[0] = (m);
                m = mid;
                while(m+1 < n && nums[m+1] == target) m++;
                ans[1] = (m);
                return ans;
            }
            else if(nums[mid] < target) s = mid+1;
            else e = mid-1;
        }
        
        return ans;
    }
};