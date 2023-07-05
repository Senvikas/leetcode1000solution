class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0;
    vector<int> v;
    v.push_back(0);
    int i=1;
        for (; i<=nums.size(); i++){
           if (nums[i-1]==0)
           v.push_back(i);
    }
    v.push_back(i);
    if (v.size()<=2) return nums.size()-1;
    if (v.size()==nums.size()+1) return 1;
    for (int i=0; i<v.size()-2; i++){
        ans=max(ans,v[i+2]-v[i]-2);
    }
    return ans;
    }
};