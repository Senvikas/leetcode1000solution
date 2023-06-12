class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size()==0)return ans;
        string s=to_string(nums[0]),k="0";
        int j=0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1]+1==nums[i])k=to_string(nums[i]);
            else{
                if(j==i-1){
                    ans.push_back(s);
                    s=to_string(nums[i]);
                    j=i;
                }
                else{
                    s=s+'-'+'>'+k;
                    ans.push_back(s);
                    s=to_string(nums[i]);
                    k="0";
                    j=i;
                }
            }
        }
        if(k=="0"){
            ans.push_back(s);
        }
        else {
            s=s+'-'+'>'+k;
            ans.push_back(s);
        }
        return ans;
    }
};