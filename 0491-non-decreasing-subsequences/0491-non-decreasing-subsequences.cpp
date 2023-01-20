class Solution {
public:
    void findSubsequencesHelper(set<vector<int>>&subsequences, vector<int>currentSubsequence, vector<int>nums, int startIdx)
    {
        for(int i=startIdx+1; i<nums.size(); i++)
        {
            if(nums[i]>=currentSubsequence[currentSubsequence.size()-1])
            {
                currentSubsequence.push_back(nums[i]);
                subsequences.insert(currentSubsequence);
                findSubsequencesHelper(subsequences, currentSubsequence, nums, i);
                currentSubsequence.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>>subsequences;

        for(int i=0; i<nums.size()-1; i++)
        {
            vector<int>currentSubsequence;
            currentSubsequence.push_back(nums[i]);
            findSubsequencesHelper(subsequences, currentSubsequence, nums, i);
        }
        vector<vector<int>>result;
        for(auto it:subsequences)
        {
            result.push_back(it);
        }
        return result;
    }
};
