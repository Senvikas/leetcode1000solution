class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st(begin(deadends),end(deadends));
        string start="0000";
        if(st.find(start)!=st.end())
          return -1;
        queue<pair<int,string>> pq;
        pq.push({0,start});
        while(!pq.empty())
        {
            auto front=pq.front();
            pq.pop();
            string curr=front.second;
            int level=front.first;

            if(curr==target)
               return level;

            
            for(int i=0;i<4;i++)
            {
                char ch=curr[i];
                char dec=ch=='0'?'9':ch-1;
                char inc=ch=='9'?'0':ch+1;
                curr[i]=dec;
                if(st.find(curr)==st.end()){
                    st.insert(curr);
                    pq.push({level+1,curr});
                }

                curr[i]=inc;
                if(st.find(curr)==st.end()){
                    st.insert(curr);
                    pq.push({level+1,curr});
                }

                curr[i]=ch;
            }
        }
        return -1;

    }
};