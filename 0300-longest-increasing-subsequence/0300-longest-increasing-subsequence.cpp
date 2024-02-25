class Solution {
public:
    int n;
    int f(int ind, int prev, vector<int> &nums, vector<vector<int>> &dp){
        //base case
        if(ind > n) return 0;
        
        //already visited
        if(dp[ind][prev] != -1) return dp[ind][prev];
        
        //1 .pick
        int pick = 0;
        if(prev == 0 || nums[prev-1] < nums[ind-1]) {
            // still two choices pick/notpick
            int chooseToPick = 1 + f(ind+1, ind, nums, dp);
            int chooseNotToPick = 0 + f(ind+1, prev, nums, dp);
            pick = max(chooseToPick, chooseNotToPick);
        }
        
        //2. not to pick
        int notPick = f(ind+1, prev, nums, dp);
                                                            
        return dp[ind][prev]  =  max(pick, notPick);
                                                            
    }
    int tabulation(vector<int>& nums) {
        n = nums.size();
        //vector<vector<int>> dp(n+2, vector<int>(n+1, 0));
        vector<int> next(n+1, 0), curr(n+1, 0);
        // Base case: if ind > n, then 0 (already set)
        
        for(int ind = n; ind >= 1; ind--) { // Loop through indices in reverse order
            for(int prev = ind-1; prev >= 0; prev--) { // Loop through prev in reverse order

                 //1 .pick
                int pick = 0;
                if(prev == 0 || nums[prev-1] < nums[ind-1]) {
                    // still two choices pick/notpick
                    // int chooseToPick = 1 + dp[ind+1][ind];
                    // int chooseNotToPick = 0 + dp[ind+1][prev];
                    // pick = max(chooseToPick, chooseNotToPick);
                    
                    
                    int chooseToPick = 1 + next[ind];
                    int chooseNotToPick = 0 + next[prev];
                    pick = max(chooseToPick, chooseNotToPick);
                    
                }

                //2. not to pick
                int notPick =  next[prev];

                curr[prev]  =  max(pick, notPick);
            }
            next = curr;
        }
        

        return curr[0]; 
    }
    
    int binSearchApp(vector<int> &nums){
        int len = nums.size();
        vector<int> replicatedLen;
        replicatedLen.push_back(nums[0]);
        int lenn = 1;
        
        for(int ind=1; ind<n; ind++){
            if(nums[ind] > replicatedLen.back()){
                lenn++;
                replicatedLen.push_back(nums[ind]);
            }
            else{
                int lbInd = lower_bound(replicatedLen.begin(), replicatedLen.end(), nums[ind])
                    - replicatedLen.begin();
                replicatedLen[lbInd] = nums[ind];
            }
        }
        
        return lenn;
    }

    
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        return binSearchApp(nums);
        return tabulation(nums);
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int ans = f(1, 0, nums, dp);  //shifte from 0 -1 to 1 0
        // for(int i=0; i<dp.size(); i++){
        //     for(int j=0; j<dp[0].size(); j++){
        //         cout << dp[i][j] << ", ";
        //     }cout << endl;
        // }cout << endl;
        
        return ans;
    }
};