class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int mi = INT_MIN;
        stack<int> st;
        int n = nums.size();
        int arr[n];
        arr[0] = nums[0];
        for(int i =1 ;i<n;i++){
            arr[i] = min(arr[i-1],nums[i]);//prefix min array
        }
        st.push(nums[n-1]);
        for(int i = n-2;i>=0;i--){
            //nums[i] will be candidate for nums of j
            //for every nums of j index we need to check for i and k conditions
            if(arr[i]<nums[i]){ //if at all on left side some minimum element exist then only we can say that at that index it is candidate for j
                while(!st.empty() && arr[i]>=st.top()){ //we need to establish n[i]<n[k] so remove all element from the stack less than n[i]
                    st.pop();
                }
                if(!st.empty() && st.top() < nums[i]) return true;
                st.push(nums[i]);
                
            }
            
        }
        return false;
        
        
    }
};