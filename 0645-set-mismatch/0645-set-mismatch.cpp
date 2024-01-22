class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int sz = nums.size();
        vector<int> arr(sz+2, -1);
        int first = 0;
        for (auto x:nums){
            if(arr[x] != -1){
                first = x;
            }
            else{
                arr[x] = x;
            }
        }
        vector<int> ans;
        ans.push_back(first);
        for (int i = 1 ; i <= sz ; i++){
            if(arr[i] == -1){
                ans.push_back(i);
            } 
        }
        return ans;
    }
};