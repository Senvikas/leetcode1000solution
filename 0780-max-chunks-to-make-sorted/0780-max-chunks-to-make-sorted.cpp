class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int chunks = 0, maxVal = 0;

        for(int i=0; i<n; i++)
        {
            maxVal = max(maxVal, arr[i]);
            if(maxVal == i)
                chunks++;
        }

        return chunks;
    }
};