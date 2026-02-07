class Solution {
public:
    string convert(string s, int nr) {
        int sz = s.size();
        vector<vector<char>> mat(nr, vector<char>(1001, ' '));
        int j = 0, ind = 0;
        while(ind < sz)
        {
            int r = nr, i = 0;
            // cout << i << " " << j << endl;
            // col first
            while(r-- && ind < sz)
            {
                mat[i][j] = s[ind];
                ind++; i++;
            }
            // fill the diag in upside manner
            i--;
            while(i>1 && ind < sz)
            {
                i--; j++;
                // cout << s[ind] << endl;
                mat[i][j] = s[ind];
                ind++;
            }
            j++;
        }

        string ans = "";
        int cnt = 0;

        // for(int i=0; i<nr; i++)
        // {
        //     for(int j=0; j<5*nr; j++)
        //     {
        //             cout << mat[i][j] <<  " ";
        //     } cout << endl;
        // }cout << endl;

        for(int i=0; i<nr; i++)
        {
            for(int j=0; j<mat[0].size(); j++)
            {
                if(mat[i][j] != ' ')
                {
                    cnt++;
                    ans.push_back(mat[i][j]);
                    if(cnt == sz)
                        return ans;
                }
            }
        }

        return ans; // never happen.
    }
};