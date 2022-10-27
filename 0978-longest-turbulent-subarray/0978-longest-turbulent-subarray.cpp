class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int currlen = 1;
        int maxlen = 1;
        int prevsign = 2;
        for(int i=1; i<n; i++)
        {
            //3cases
            //1. sign is >
            if(arr[i] > arr[i-1])
            {
                //agian 2 cases
                //1. prevsign also was >  : means we can have atleast last two elements as ans
                if(prevsign == 1)
                {
                    currlen = 2;
                }
                //2. prevsign was different
                else
                {
                    currlen++;
                }
                //update the prevsign
                prevsign = 1;
            }
            //2. sign is <
            else if(arr[i] < arr[i-1])
            {
                if(prevsign == 0)
                {
                    currlen = 2;
                }
                else
                {
                    currlen++;
                }
                prevsign = 0;
            }
            //3rd case
            else
            {
                currlen = 1;
                prevsign = 2;
            }
            maxlen = max(maxlen, currlen);
        }
        return maxlen;
    }
};