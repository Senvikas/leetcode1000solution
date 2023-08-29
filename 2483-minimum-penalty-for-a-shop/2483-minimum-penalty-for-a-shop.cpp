class Solution {
public:
    int bestClosingTime(string c) {
        int n = c.length();
        int ty = 0;
        for(int i=0; i<n; i++)
        {
            if(c[i] == 'Y')ty++;
        }
        int tn = n-ty;
        if(ty == n) return n;
        if(ty == 0) return 0;
        cout<<ty<<tn<<endl;
        int pen = ty;
        int ind = 0;
        int cy = 0, cn = 0;
        for(int i=0; i<n; i++)
        {
            if(c[i] == 'Y') cy++;
            else cn++;
            int penl = (ty-cy) + cn;
            if(penl < pen)
            {
                pen = penl;
                ind = i+1;
            }
        }
        
        return ind;
    }
};