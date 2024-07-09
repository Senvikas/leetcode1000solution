class Solution {
public:
    int maxDepth(string s) {
      int d = 0, md = 0;
        for(char c: s){
            if(c == ')'){
                if(d>0) d--;
            }
            else if(c == '('){
                d++;
                md = max(md, d);
            }
        }
        return md;
    }
};