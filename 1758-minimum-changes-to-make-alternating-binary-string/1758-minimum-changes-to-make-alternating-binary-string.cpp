class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int ct0=0,ct1=0;

// Count operations to make the string alternate
        for (int i=0;i<n;i++) {
            if(i%2==0){
                if(s[i]=='0')ct0++;
                else ct1++;
            } 
            else{
                if(s[i]=='1') ct0++;
                else ct1++;  
            }
        }
        return min(ct0, ct1);
    }
};