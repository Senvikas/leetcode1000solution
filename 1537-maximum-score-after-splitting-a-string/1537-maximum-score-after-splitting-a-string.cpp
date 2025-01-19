class Solution {
public:
    int maxScore(string s) {
     int count0=0,lcount=0,ans=0;
        
        for(auto x:s) if(x == '0') count0+=1;
        
        int count1 = s.length()-count0;
        int rcount=count1;
        
        for(int i=0;i<s.length()-1;i++){
            if(s[i] == '0'){
                lcount++;
                ans = max( ans,(lcount + rcount));
            }
            
           else if(s[i]== '1' ){
                rcount--;
                ans = max(ans,(lcount + rcount));
            }            
        }       
        return ans;
    
    }
};