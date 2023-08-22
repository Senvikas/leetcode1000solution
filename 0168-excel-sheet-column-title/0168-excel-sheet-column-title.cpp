class Solution {
public:
    string convertToTitle(int columnNumber) {
        int c=0;
        int n=columnNumber;
        string s;
        int d=0;
        n--;
        while(n>=0){
        char c=char('A'+n%26);
        s=s+c;
        n=n/26;
        n--;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};