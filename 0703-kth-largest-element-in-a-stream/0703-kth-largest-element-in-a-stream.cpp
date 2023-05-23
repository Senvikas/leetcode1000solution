class KthLargest {
public:
    priority_queue <int, vector<int>, greater<int> > q;
    int s;
    KthLargest(int k, vector<int>& nums) {
        int i=0;s=k;
        for(;i<k && i<nums.size();i++){
            q.push(nums[i]);
        }
        while(i<nums.size()){
            if(q.top()<nums[i]){
                q.pop();
                q.push(nums[i]);
            }
            i++;
        }
    }
    
    int add(int val) {
        if(q.size()<s)
            q.push(val);
        else if(!q.empty() && q.top()<val){
            q.pop();
            q.push(val);
        }
        return q.top();
    }
};