class Solution {
public:
    int MOD= 1e9+7;
    int solve(int n, int m, int K)
    {
        if(m<K)
        {
            return 0;
        }

        //space optimized
        //vector<vector<int>> curr(m+1, vector<int> (m+1, 0));
        //vector<vector<int>> next(m+1, vector<int> (m+1, 0));

        //more space optimized
        vector<vector<int>> curr(m+1, vector<int> (K+2, 0));
        vector<vector<int>> next(m+1, vector<int> (K+2, 0));

        //base case
        for(int j=0;j<=m;j++)
        {
            next[j][K]=1;
        }

        for(int i=n-1;i>=0;i--) //len
        {
            for(int j=m;j>=0;j--) //maxele
            {
                for(int k=K;k>=0;k--) //cost (start from K for more optimization)
                {
                    int count=0;
                    for(int l=1;l<=m;l++)
                    {
                        if(l>j && k!=m)
                        count= (count+ next[l][k+1])%MOD;
                        else
                        count= (count+ next[j][k])%MOD;
                    }
                    curr[j][k]= count;
                }
            }
            next=curr;
        }
        return next[0][0];
    }
    int numOfArrays(int n, int m, int k) {
        return solve(n, m, k);
    }
};