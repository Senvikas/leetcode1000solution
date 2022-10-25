class Solution {
public:
    int pivot(vector<int> &arr, int n){
         int s = 0; int e = n-1;
        while(s<e){
            int mid = (s+e)>>1;
            if(arr[mid] >= arr[0])
                s = mid+1;
            else 
                e = mid;
        }
        return s;
    }
    
    int findMin(vector<int>& nums) {
        //the question is to find the pivot index
        int n=nums.size();
        int s = pivot(nums, n);
        if(s==n-1) return nums[0] > nums[s] ? nums[s] : nums[0];
        return nums[s];
    }
};