class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int ma1 = nums[0], ma2 = nums[1], mi1 = nums[2], mi2 = nums[3];
        vector<int> four = {ma1, ma2, mi1, mi2};
        sort(four.begin(), four.end());
        mi1 = four[0];
        mi2 = four[1];
        ma1 = four[3];
        ma2 = four[2];
    
        for(int i=4; i<nums.size(); i++){
            int ele = nums[i];
            
            // should max be updated
            if(ele > ma2 || ele > ma1){
                if(ele > ma1){
                    ma2 = ma1;
                    ma1 = ele;
                }else
                    ma2 = ele;
            }
            
            //should min be updated
            if(ele < mi2 || ele < mi1){
                if(ele < mi1){
                    mi2 = mi1;
                    mi1 = ele;
                }else
                    mi2 = ele;
            }
            
        }
        
        int first = mi1 * mi2;
        int sec = ma1 * ma2;
        return -( first - sec);
    }
};