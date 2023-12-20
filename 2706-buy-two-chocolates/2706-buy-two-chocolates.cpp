class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int mini1 =INT_MAX;
        int mini2 =INT_MAX;
        for(auto it:prices){
            if(it<mini1){
                if(mini1 == INT_MAX){
                    mini1 =it;
                }
                else{
                    mini2 =mini1;
                    mini1 =it;
                }
            }
            else if(it<mini2){
                mini2 =it;
            }
        }
        if(mini1+mini2<=money){
            return money-mini1-mini2;
        }
        return money;
    }
};