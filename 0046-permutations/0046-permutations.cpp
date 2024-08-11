class Solution {
public:
     void getPermutations(vector<int> &nums, vector<vector<int>> &ans, vector<int> perm, int ind, vector<int> &mapping){
        if(ind == nums.size()){
            ans.push_back(perm);
            return;
        }
         
         for (int i = 0; i < nums.size(); ++i) {
            if (mapping[i] == 0) {
                perm.push_back(nums[i]);
                mapping[i] = 1;
                getPermutations(nums, ans, perm, ind + 1, mapping);
                perm.pop_back();
                mapping[i] = 0;
            }
        }
         
         
         
         return;
     }
    
    void getPermutations(vector<int> &nums, vector<vector<int>> &ans, vector<int> perm, int ind){
        if(ind == nums.size()){
            ans.push_back(perm);
            return;
        }
        
        for(int i=ind; i<nums.size(); i++){
            swap(nums[i], nums[ind]);
            perm.push_back(nums[ind]);
            getPermutations(nums, ans, perm, ind+1);
            swap(nums[i], nums[ind]);
            perm.pop_back();
        }
        
        return ;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>> ans;
        vector<int> perm;
        vector<int> mapping(nums.size(), 0);
        
        getPermutations(nums, ans, perm, 0, mapping);
        
        return ans;
    }
};