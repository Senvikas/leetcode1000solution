class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        
        for(auto itr=mpp.begin(); itr!=mpp.end();itr++){
            if(itr->second==1){
                return itr->first;
            }
        }
        return -1;
    }
};