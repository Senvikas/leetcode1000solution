class Solution {
public:
    int dp[100001] ;
    int fun(int n){
        if(n == 0){
            return 0;
        }
        if(n == 1 || n<0){
            return 1000000 ;
        }

        if(dp[n] != -1){
            return dp[n] ;
        }

        int ans = 1000000;
        if(n/2 >=1){
            ans = min(ans , 1 + fun(n-2));
        }
        if(n/3 >= 1){
            ans = min(ans , 1 + fun(n-3));
        }

        return dp[n] = ans ;
    }
    int minOperations(vector<int>& nums) {
        memset(dp , -1 , sizeof(dp));
        map<int,int>m;

        for(auto x : nums){
            m[x]++;
        }

        int ans = 0 ;

        for(auto it=m.begin() ; it!=m.end() ; it++){
            int res = fun(it->second);
            if(res >= 1000000){
                return -1 ;
            }
            ans += res ;
        }

        return ans ;

    }
};