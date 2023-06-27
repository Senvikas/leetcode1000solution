class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();

        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0; i<n1; i++){
            for(int j=0; j<n2; j++){
                int sum = nums1[i] + nums2[j];
                if(pq.size() < k){
                    pq.push({sum,{nums1[i],nums2[j]}});
                }
                else if(pq.top().first > sum){
                    pq.pop();
                    pq.push({sum,{nums1[i],nums2[j]}});
                }
                else{
                    break;
                }
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            ans.push_back({x,y});
            pq.pop();
        }
        return ans;
    }
};