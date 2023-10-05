class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int c1 = 1e9+1, c2 = 1e9+1, f1 = 0, f2 = 0;
        for(auto i: nums){
            if(i == c1) f1++;
            else if(i == c2) f2++;
            
            else {
                if(f1 == 0){
                    c1 = i; f1++;
                }
                else if(f2 == 0){
                    c2 = i; f2++;
                }
                else{
                    f1--;
                    f2--;
                }
            }
            
            
        }
        
        vector<int> ans; f1 = 0; f2 = 0;
        for(auto i: nums){
            if(i==c1) f1++;
            if(i == c2) f2++;
        }
        
        if(f1 > n/3) ans.push_back(c1);
        if(f2 > n/3) ans.push_back(c2);
        return ans;
    }
};