class Solution {
public:
    int solve(vector<vector<int>>&dp, vector<int>&jobDiff, int ind, int rem)
    {
        if(rem==0 && ind<jobDiff.size())return 1e5;
        if(ind==jobDiff.size() && rem!=0)
        {
            return 1e5;
        }
        if(ind==jobDiff.size())return 0;
        if(dp[ind][rem]!=-1)return dp[ind][rem];
        dp[ind][rem]=1e5;
        int maxi = jobDiff[ind];
        for(int i=ind+1;i<=jobDiff.size();i++)
        {
            maxi = max(maxi,jobDiff[i-1]);
            dp[ind][rem]=min(dp[ind][rem],maxi+solve(dp,jobDiff,i,rem-1));
        }
        return dp[ind][rem];
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) 
    {
        int n = jobDifficulty.size();
        if(d>n)return -1;
        vector<vector<int>>dp(n,vector<int>(d+1,-1));
        return solve(dp,jobDifficulty,0,d);
    }
};