class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first = nums[0], sec = nums[1];
        if(first < sec){
            swap(first, sec);
        }
       
        for(int i=2; i<nums.size(); i++){
            if(first < nums[i]){
                sec = max(sec, first);
                first = nums[i];
            }else if(sec < nums[i])
                sec = nums[i];
        }
        return (first-1) * (sec-1);
    }
};