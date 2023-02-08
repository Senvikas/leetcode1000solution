class Solution {
public:
    int jump(vector<int>& arr) {
      int jumps = 0; 
        int current = 0;
        int max_reach = 0;
        for(int i=0; i<arr.size()-1; i++)
        {
            max_reach = max(max_reach, arr[i] + i);
            
            if(i==current)
            {
                current = max_reach;
                jumps++;
            }
        }
        return jumps;  
    }
};