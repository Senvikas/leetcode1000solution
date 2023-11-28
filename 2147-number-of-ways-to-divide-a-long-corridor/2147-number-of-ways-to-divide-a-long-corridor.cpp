int mod = 1000000007;
class Solution {
public:
    int numberOfWays(string corridor) {
        int count=0;
             for(int i=0;i<corridor.size();i++){
                 if(corridor[i]=='S'){
                     count++;
                 }
             }
             
             if(count%2!=0){
                 return 0;
             }
             if(count==2){
                 return 1;
             }
             if(count==0){
                 return 0;
             }
count=0;
        string s=corridor;
        while(s[s.length()-1]=='P'){
            s.pop_back();
        }
        int left=0,right=0,tempans=0;
        long long ans=1;
        for(right=0;right<s.length();right++){
            if(count>2){
                left=right;
                count=1;
                ans=((ans%mod)*(tempans%mod))%mod;
                tempans=0;

            }
            if(s[right]=='S'){
                count++;
            }
            if(count==2){
                tempans++;
            }
        }
        return ans%mod;
    }
};