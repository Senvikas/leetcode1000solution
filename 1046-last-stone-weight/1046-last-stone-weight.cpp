class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;

        for( auto i : stones ){
            q.push(i);
        }

        while( q.size() > 1 ){
            int one = q.top();
            q.pop();
            int two = q.top();
            q.pop();

            if( one != two ){
                int ele = abs( one - two );
                q.push(ele);
            }
        }

        int ans = 0;

        if( !q.empty() ){ ans = q.top(); }

        return ans;
    }
};