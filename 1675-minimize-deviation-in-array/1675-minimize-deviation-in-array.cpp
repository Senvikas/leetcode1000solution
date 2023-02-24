class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int ans = INT_MAX;
        priority_queue<int> pq;
        for(int i:nums){
            if(i%2==1) i*=2;
            ans=min(ans,i);
            pq.push(i);
        }
        int diff = INT_MAX;
        while(pq.top()%2==0)
        {
            int maxi = pq.top();
            pq.pop();
            diff = min(diff,maxi-ans);
            ans = min(maxi/2,ans);
            pq.push(maxi/2);
        }
        return min(diff,pq.top()-ans);
    }
};