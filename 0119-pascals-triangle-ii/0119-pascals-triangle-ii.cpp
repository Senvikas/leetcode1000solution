class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return {1};
        vector<int> ans, prev(1, 1);
        
        for(int i=2; i<=rowIndex+1; i++){
            ans.resize(i);
            
            for(int j=0; j<i; j++){
                if(j==0 || j==i-1) ans[j] = 1;
                else{
                    ans[j] = prev[j-1] + prev[j];
                }
            }
            
            prev = ans;
        }
        return ans;
    }
};