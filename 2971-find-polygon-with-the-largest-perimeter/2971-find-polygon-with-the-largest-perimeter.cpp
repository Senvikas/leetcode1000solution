class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        //[1,12,1,2,5,50,3]
        sort(nums.begin(), nums.end());
        //[1,1,2,3,5,12,50]
        int n = nums.size();
        
        
        vector<long long> pref(n);
        //[0,0,0,0,0,0,0]
        
        pref[0] = nums[0];
        //[1,0,0,0,0,0,0]
        
        for(int i=1; i<n; i++){
            pref[i] = pref[i-1] + nums[i];
        }
        //[1,2,4,7,12,24,74]
        
        int ind = n-1;  // ind = 6
        while(ind-1 >= 0 && pref[ind] >= 2*pref[ind-1]) ind--;
        //ind = 4;
        if(ind < 2) return -1;
        
        long long ans = 0;
        for(int i=0; i<=ind; i++) ans += nums[i];
        
        return ans;
        
    }
};