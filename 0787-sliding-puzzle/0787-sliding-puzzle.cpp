class Solution {
public:
    string final = "123450";
    vector<vector<int>> swappingInds = {{1,3}, {0,2,4}, {1,5}, {0,4}, {1,3,5}, {4,2}};

    int bfs(string &brd, int ind)
    {
        queue<pair<string,int>> q;
        q.push({brd, ind});
        set<string> st;
        st.insert(brd);

        int level = 0;

        while(!q.empty())
        {
            int sz = q.size();

            while(sz--)
            {
                auto node = q.front();
                q.pop();

                string nodeBrd = node.first;
                ind = node.second;

                if(nodeBrd == final)
                    return level;

                for(auto &sInd : swappingInds[ind])
                {
                    string str = nodeBrd;
                    swap(str[ind], str[sInd]);
                    if (st.find(str) == st.end()) {
                        st.insert(str);
                        q.push({str, sInd});
                    }
                }
                
            }


            level++;
        }

        return -1;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        string brd = "";
        int ind;
        for(int i=0; i<2; i++)
        {
            for(int j=0; j<3; j++)
            {
                brd.push_back('0' + board[i][j]);
                if(brd.back() == '0')
                    ind = brd.size() - 1;
            }
        }

        return bfs(brd, ind);
    }
};