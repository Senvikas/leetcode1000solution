class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans, odd;
        int n = nums.size();
        for(auto a : nums){
            if(a%2 == 0) ans.push_back(a);
            else odd.push_back(a);
        }
        for(auto a: odd) ans.push_back(a);
        return ans;
    }
};