class Solution {
public:
    int largestVariance(string s) {
        int res = 0;
        vector<int> freq(26,0);
        for(int ch : s) {
            freq[ch-'a']++;
        }
        for(char c1 = 'a'; c1<='z'; c1++) {
            for(char c2 = 'a'; c2<='z'; c2++) {
                if(c1 == c2 || freq[c1-'a']==0 || freq[c2-'a']==0) continue;
                
                int ch1 = 0, ch2 = 0, ch3 = 0, ch4 = 0;
                int res1=0, res2=0;

                for(int i=0, j=s.size()-1; i<s.size(); i++, j--) {
                    if(s[i] == c1) ch1++;
                    if(s[i] == c2) ch2++;

                    if(s[j] == c1) ch3++;
                    if(s[j] == c2) ch4++;

                    if(ch1 > ch2) {ch1=0; ch2=0;}
                    if(ch3 > ch4) {ch3=0; ch4=0;}

                    if(ch2>0 && ch1>0)
                        res1 = max(res1, ch2-ch1);
                    
                    if(ch4>0 && ch3>0)
                        res2 = max(res2, ch4-ch3);
                    
                    
                }

                res = max({res,res1, res2});
            }
        }

        return res;
    }
};