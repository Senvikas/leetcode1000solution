class Solution {
public:
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin() , pairs.end() ) ;
        int count = 0 ;
        vector<int> temp = pairs[0] ;
        for(int i = 1 ; i < pairs.size() ; i++)
        {
            if(pairs[i][0] > temp[1])
            {
                count++ ;
                temp = pairs[i];
            }
            else
            {
                if(temp[1] > pairs[i][1]){
                    temp = pairs[i] ;
                }
            }
        }
        return count + 1;
    }
};