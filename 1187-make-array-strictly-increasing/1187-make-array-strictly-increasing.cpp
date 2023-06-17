class Solution {
vector<unordered_map<int,int>>dp;
private:
    int help(vector<int>& arr1, vector<int>& arr2,int start ,int prev){
        if(start==arr1.size()){
            return 0;
        }
        if(dp[start][prev])
            return dp[start][prev];
            
        int nt=INT_MAX-1,t;
        if(arr1[start]>prev){
            nt=help(arr1,arr2,start+1,arr1[start]);
            int upr=upper_bound(arr2.begin(),arr2.end(),prev)-arr2.begin();
            if(upr==arr2.size() or arr2[upr]==prev)
                return min(nt,INT_MAX-1);
            t=1+help(arr1,arr2,start+1,arr2[upr]);
           
        }
        else{
            int upr=upper_bound(arr2.begin(),arr2.end(),prev)-arr2.begin();
            if(upr==arr2.size() or arr2[upr]==prev)
                return INT_MAX-1;
            t=1+help(arr1,arr2,start+1,arr2[upr]);
        }
        return dp[start][prev]=min(nt,t);
    }

public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int m=arr2.size();
        dp.resize(n+1);
        sort(arr2.begin(),arr2.end());
        return help(arr1,arr2,0,-1)>=INT_MAX-1?-1:help(arr1,arr2,0,-1);      
    }
};