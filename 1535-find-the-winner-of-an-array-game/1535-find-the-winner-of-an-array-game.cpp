class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        
        if(k>arr.size())
        {
            for(int i =1;i<arr.size();i++)
                if(arr[0]<arr[i])
                    swap(arr[0],arr[i]);

            return arr[0];
        }

            int tmp =  0;
            int i=1;
            while(tmp<k)
            {
                if(arr[0]<arr[i])
                {
                    swap(arr[0],arr[i]);
                    tmp = 0;

                }
                    tmp++;
                
                i++;
                if(i>arr.size()-1)
                    i = 1;
                    
            }


        return arr[0];

    }
};