class Solution {
public:
    int digCount(int num){
        int cnt = 0;
        while(num){
            cnt++;
            num = num/10;
        }
        return cnt;
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int ldcnt = digCount(low);
        int hdcnt = digCount(high);
        
        for(int dcnt=ldcnt; dcnt<=hdcnt; dcnt++){
            
            for(int sw=0; sw<=9-dcnt; sw++){
                int num = 0;
                
                for(int dig=1; dig<=dcnt; dig++){
                num = (num*10) + (dig + sw);
                if(num > high) break;
                }
                
                if(num > high) break;
                if(num>=low)
                ans.push_back(num);
                num = 0;
            }
            
        }   
        return ans;
    }
};