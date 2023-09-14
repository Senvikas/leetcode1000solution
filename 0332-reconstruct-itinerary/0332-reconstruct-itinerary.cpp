class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>> adj; // making adjacency list
        int n=tickets.size();
        vector<string> ans;
        //make graph
        for(int i=0;i<n;i++)
        {
            adj[tickets[i][0]].insert(tickets[i][1]);
        }
        stack<string> mystack;
        mystack.push("JFK");
        while(!mystack.empty())
        {
            string src = mystack.top();
            if(adj[src].size()==0) //no further travel possiblle
            {
                ans.push_back(src);
                mystack.pop();
            }
            else
            {
                auto dst = adj[src].begin();//keep destination pointer at the beginning
                mystack.push(*dst); // The first destination airport code pointed to by the iterator dst is pushed onto the stack, indicating the next stop in the itinerary.
                adj[src].erase(dst); //After pushing the destination onto the stack, it is removed from the multiset of destinations associated with the current source airport.
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};