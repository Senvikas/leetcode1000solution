class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>> pairVec;
        for(int i=0; i<n; i++){
            pairVec.push_back({nums[i], i});
        }
        
        sort(pairVec.begin(), pairVec.end());
        
        int i = 0, j = n-1;
        while(i<j){
            int sum =  pairVec[i].first + pairVec[j].first;
            if(sum == target) return {pairVec[i].second, pairVec[j].second};
            else if(sum < target) i++;
            else j--;
        }
        return {-1, -1};
    }
};