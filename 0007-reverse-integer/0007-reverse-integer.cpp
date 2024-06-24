class Solution {
public:
    int reverse(int x) {
        
        int ifNeg = 0;
        if(x < 0) ifNeg = 1;
        x = abs(x);
        int num = INT_MAX;
        vector<int> digs(10);
        int i = 0;
        while(num){
            int dig = num%10;
            num /= 10;
            
            digs[i++] = dig;
        }
        
        i = 0; int j = 9;
        
        while(i <= j){
            int dig = digs[i];
            digs[i] = digs[j];
            digs[j] = dig;
            i++; j--;
        }
        
        if(ifNeg) digs[9] += 1; 
   
        
        
        bool check = true;
        
        int n = x;
        int ans = 0;
        
        i = 0;
        
        int cnt = 0;
        while(n){
            cnt++;
            n /= 10;
        }
        
        n = x;
        
        while(n){
            int back = n%10;
            n /= 10;
            if(check && cnt == 10){
                if(back > digs[i]) return 0;
                if(back < digs[i]){
                    check = false;
                }
            }
                
           
              ans = ans*10 + back;
            i++;

        }
        if(ifNeg) ans = -ans;
        return ans;
    }
};