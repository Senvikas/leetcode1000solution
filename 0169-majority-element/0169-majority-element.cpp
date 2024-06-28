class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int n = nums.size();
        int c1 = 0, c2 = 0, e1 = -1e9 - 1, e2 = -1e9-2;
        
        for(int i=0; i<n; i++){
            int num = nums[i];
            //3 cond
            //1. first number matches
            if(e1 == num) c1++;
            else if(e2 == num) c2++;
            
            else{
                if(c1 == 0 && c2 == 0) {
                    c1++; e1 = num;
                }
                else if(c1 == 0 && c2 > 0){
                    e1 = num; c1++; //c2--;
                }else if(c2 == 0 && c1 > 0){
                    e2 = num; c2++;
                }else{
                    c1--; c2--;
                }
            }
            
        }
        
        int ans = e1;
        if(c1 < c2) ans = e2;
        
        int cnt = 0;
        for(auto &ele: nums) if(ele == ans) cnt++;
        
        if(cnt >= n/2) return ans;
        return -1;
    }
};