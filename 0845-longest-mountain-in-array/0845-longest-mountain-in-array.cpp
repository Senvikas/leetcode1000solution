class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int low = 0;
        int high = 0;
        int maxlen = 0;
        
        string s = "";
        for(int i=0; i<n-1; i++)
        {
            if(arr[i] > arr[i+1])
                s += '>';
            else if(arr[i] < arr[i+1])
                s += '<';
            else
                s += '=';
        }
        for(int i=0; i<n-1; i++){
            cout<<s[i];
        }cout<<endl;
        
        for(int i=0; i<n; i++){
            //small is found
            if(s[i] == '<')
            {
                if(high != 0)
                {
                    high = 0;
                    low = 1;
                }
                else
                {
                    low++;
                }
            }
            else if(s[i] == '>')
            {
                if(low != 0)
                {
                    high++;
                    maxlen = max(maxlen, high+low+1);
                }
            }
            else{              // = found
                // maxlen = max(maxlen, high+low);
                low = 0;
                high = 0;
            }
        }
        
        
        return maxlen;
    }
};