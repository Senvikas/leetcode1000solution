class Solution {
public:
    int pivotInteger(int n) {
        int ts = n*(n+1)/2;
        cout<<ts<<endl;
        for(int i=1; i<=n; i++)
        {
            if( (i*(i+1))/2 == ts - i*(i+1)/2 + i )return i;
        }
        return -1;
    }
};