#define mod 1000000007
class Solution {
public:
    vector<char>v={'a','e','i','o','u'};
    int f(int n,char s,map<pair<char,int>,int>&dp){
        if(n==0){ 
            return 1;
        }
        if(dp.contains({s,n})) return dp[{s,n}];
        int ans=0;
        if(s=='#'){
            for(int i=0;i<v.size();++i){
                ans=(ans+f(n-1,v[i],dp))%mod;
            }
        }
        else if(s=='a'){ 
            ans=(ans+f(n-1,'e',dp))%mod;
        }
        else if(s=='e'){
            ans=(ans+f(n-1,'a',dp)+f(n-1,'i',dp))%mod;
        }
        else if(s=='i'){
            for(int i=0;i<v.size();++i){
                if(v[i]!='i') ans=(ans+f(n-1,v[i],dp))%mod;
            }
        }
        else if(s=='o'){
            ans=(ans+f(n-1,'i',dp)+f(n-1,'u',dp))%mod;
        }
        else if(s=='u'){
            ans=(ans+f(n-1,'a',dp))%mod;
        } 
        return dp[{s,n}]=ans;
    }
    int countVowelPermutation(int n) {
        map<pair<char,int>,int>dp;
        return f(n,'#',dp);
    }
};