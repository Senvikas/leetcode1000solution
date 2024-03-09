class Solution {
public:
    int f(vector<int> &nums, int t, int i, int j){
        
        int ans = 0;
        
        while(i<=j){
            int mid = (i+j)/2;
            
            //found
            if(nums[mid] == t) return mid;
            
            //greater
            if(nums[mid] > t){
                j = mid-1;
                if(j<i) return i;
            }
            
            //smaller
            else{
                i = mid+1;
                
                if(i>j) return i;
            }
        }
        
        return -1;
    }
    int searchInsert(vector<int>& nums, int target) {
        
        int n = nums.size();
        return f(nums, target, 0, n-1);
    }
};