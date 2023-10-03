class Solution {
public:
    int sumTillN(int n){
        return (n*(n-1))/2;
    }
    int numIdenticalPairs(vector<int>& nums) {
        vector<int>freq(101, 0);
        for(auto num : nums){
            freq[num]++;
        }
        int ans = 0;
        for(auto frequ: freq){
            if(frequ) ans += sumTillN(frequ);
        }
        return ans;
    }
};