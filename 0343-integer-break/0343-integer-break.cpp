class Solution {
public:
    int integerBreak(int n) {
        int half = n/2+1;
        int ans = 1;
        
        for(int i=2; i<=half; i++){
            int part = i;
            int brokeval = n/i;
            int mod = n%i;
            int mul = 1;
            
            while(mod){
                mul = mul*(brokeval+1);
                part--;
                mod--;
            }
            
            while(part){
                mul = mul*brokeval;
                part--;
            }
            
            ans = max(ans, mul);
        }
        return ans;
    }
};