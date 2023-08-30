class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long operation =0;
        for(int i = n-2 ; i >= 0 ;i--){

            if(nums[i] <= nums[i+1]){
                continue;
            } 
            int part = nums[i]/nums[i+1];   

            if(nums[i] % nums[i+1] != 0){
                part++; // if the value is not divisable by the next number (12 7 6 29) (7 / 6= 1) so extra 1 for that +1 ;
            }

            operation += (part-1);  // suppose 12 % 3=  4 4 parts but operation part -1 , that why 

            nums[i] = nums[i] / part;  // find the valid partition , 7 / 6 = 1; part = 2 so 7 / 2= 3 ;

        }
        return operation ;
    }
};