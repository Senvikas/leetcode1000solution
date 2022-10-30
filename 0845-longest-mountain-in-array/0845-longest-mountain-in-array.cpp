class Solution
{
    public:
        int longestMountain(vector<int> &arr)
        {
            int n = arr.size();
            int low = 0;
            int high = 0;
            int maxlen = 0;

            for (int i = 0; i < n-1; i++)
            {
               	//small is found
                if(arr[i] < arr[i+1])                         //if (s[i] == '<')
                {
                    if (high != 0)
                    {
                        high = 0;
                        low = 1;
                    }
                    else
                    {
                        low++;
                    }
                }
                //greater element found
                else if (arr[i] > arr[i + 1])                                     //else if(s[i] == '>')
                {
                    if (low != 0)
                    {
                        high++;
                        maxlen = max(maxlen, high + low + 1);
                    }
                }
                else // = found
                {
                    low = 0;
                    high = 0;
                }
            }

            return maxlen;
        }
};