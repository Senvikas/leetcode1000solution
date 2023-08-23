class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> mp;
        int n=s.length();

        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
            if(n%2==0&&mp[s[i]]>n/2)
            return "";
            if(n%2!=0&&mp[s[i]]>n/2+1)
            return "";
        }  


        priority_queue<pair<int,char>> pq;

        for(auto itr:mp)
        {
            pq.push({itr.second,itr.first});
        }  
        string ans;

        while(!pq.empty())
        {
            int x=pq.top().first;
            char c=pq.top().second;
            ans+=pq.top().second;
             pq.pop();
             int y=1;
             char cc='a';
             if(!pq.empty())
             {
              y=pq.top().first;
              cc=pq.top().second;
             ans+=pq.top().second;
             pq.pop();
             }
            if(x!=1)
            {
                pq.push({x-1,c});
            }
            if(y!=1)
            {
                pq.push({y-1,cc});
            }
           
            
            
        }    
        return ans;
      
        
    }
};