class Solution {
public:
    int arraySign(vector<int>& arr) {
        int count = 0;
        for(int i = 0; i < arr.size(); i++) 
        {
            if(arr[i] == 0) return 0;
            if(arr[i] < 0) count++;
        }
        return count%2 ? -1 : 1;
    }
};