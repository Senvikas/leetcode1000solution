class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        int n = arr.size();
        int count =0, sum=0;
        for(int i=0; i<n; i++)
        {
            sum += arr[i];
            
            if(sum == k)
                count++;
            
            if(m.find(sum-k) != m.end())
                count += m[sum-k];
            
                m[sum]++;

        }
        return count;
    }
};