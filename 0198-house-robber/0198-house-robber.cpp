    class mySolution{
        public:
        int spaceOpt(vector<int> &moneyInHouses){
            int n = moneyInHouses.size();

            //base case
            int next = moneyInHouses[n-1];
            int next2 = 0;

            for(int ind=n-2; ind>=0; ind--){
                    int take = moneyInHouses[ind] + next2;                //next2 = dp[ind+2];
                    int notTake = next;                                        //next = dp[ind+1];

                    int curr = max(take, notTake);
                    next2 = next;
                    next = curr;
            }

            return next;
        }

        int Tabulation(vector<int> &moneyInHouses){
            int n = moneyInHouses.size();

            vector<int> dp(n+1, 0);
           //base case
            dp[n] = 0;
            dp[n-1] = moneyInHouses[n-1];

            for(int ind=n-2; ind>=0; ind--){
                    int take = moneyInHouses[ind] + dp[ind+2];
                    int notTake = dp[ind+1];

                    dp[ind] = max(take, notTake);
            }

            return dp[0];
        }

        int solveRec(int ind, int n, vector<int> &moneyInHouses, vector<int> &dp){
            //base case
            if(ind == n-1) return moneyInHouses[ind];
            if(ind >= n) return 0;

            if(dp[ind] != -1) return dp[ind];    //2nd step

            // I will do one part + Reamining Recursion
            int take = moneyInHouses[ind] + solveRec(ind+2, n, moneyInHouses, dp);
            int notTake = solveRec(ind+1, n, moneyInHouses, dp);

            //return whatever max you can make
            return dp[ind] = max(take, notTake);        //1st step
        }

        int houseRobber(vector<int> &moneyInHouses){
            int n = moneyInHouses.size(); 
            /*
            vector<int> dp(n, -1);      //0th step
            return solveRec(0, n, moneyInHouses, dp);
            */

           //Tabulation
           //return Tabulation(moneyInHouses);

           //space optimization
           return spaceOpt(moneyInHouses);
        }
    };

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        mySolution obj;
        // return obj.solveRec(0, n, nums, dp);
        
        // return obj.Tabulation(nums);
        
        return obj.spaceOpt(nums);
    }
};