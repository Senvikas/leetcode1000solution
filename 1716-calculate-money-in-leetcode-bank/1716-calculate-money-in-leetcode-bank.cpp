class Solution {
public:
    int totalMoney(int n) {
        int start=28; 
        int integral= n/7; 
        int remainder= n%7; 
        int ammount=((double)integral/2)*(56+ (integral-1)*7); 
        
        integral++; 
        int i=1; 
        while(i<=remainder){
            ammount+=integral;
            integral++;  
            i++; 
        }
        return ammount; 
    }
};