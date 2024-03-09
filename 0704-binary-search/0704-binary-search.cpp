class Solution {
public:
    int f(vector<int> &nums, int t, int i, int j){
        if(i > j) return -1;
        
        int mid = (i+j)/2;
        
        if(nums[mid] == t) return mid;
        
        if(nums[mid] > t) return f(nums, t, i, mid-1);
        
        return f(nums, t, mid+1, j);
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return f(nums, target, 0, n-1);
    }
};