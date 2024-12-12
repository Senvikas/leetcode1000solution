class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;

        for(auto &ele: gifts)
        {
            pq.push(ele);
        }

        while(!pq.empty() && k--)
        {
            int maxGifts = pq.top();
            if(maxGifts == 1)
                break;
                
            pq.pop();


            int leave = sqrt(maxGifts);
            pq.push(leave);
        }

        long long ans = 0;
        while(!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};