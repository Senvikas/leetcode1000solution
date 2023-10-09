class Solution {
public:
    int binSearch(vector<int> &nums, int t, int s, int e){
        if(s > e) return -1;
        
        int mid = s + (e-s)/2;
        if(nums[mid] == t) return mid;
        if(nums[mid] > t) return binSearch(nums, t, s, mid-1);
        return binSearch(nums, t, mid+1, e);
        
    }
    

    vector<int> searchRange(vector<int>& nums, int target) {
        int ind = binSearch(nums, target, 0, nums.size()-1);
        if(ind == -1) return {-1, -1};
        vector<int> ans;
        
        int i = ind;
        while(i >= 0 && nums[i] == target){
            i--;
        }
        ans.push_back(i+1);
        while(ind < nums.size() && nums[ind] == target){
            ind++;
        }
        ans.push_back(ind-1);
        
        return ans;
    }
};