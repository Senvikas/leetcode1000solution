class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>u;
        for(int i=0;i<nums1.size();i++)
        u.push_back(make_pair(nums2[i],nums1[i]));
        sort(u.rbegin(),u.rend());
        long long cursum=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<k-1;i++)
        {
            pq.push(u[i].second);
            cursum+=u[i].second;
        }
        long long ans=0;
        for(int i=k-1;i<nums1.size();i++)
        {
            pq.push(u[i].second);
            cursum+=u[i].second;
            ans=max(ans,cursum*u[i].first);
            cursum-=pq.top();
            pq.pop();
        }
        return ans;
    }
};