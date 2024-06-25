class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x<10) return true;
        vector<int> digs(10, -1);
        
        int i = 0;
        while(x){
            int dig = x%10;
            x /= 10;
            digs[i++] = dig;
        }
        
        int j = i-1; i = 0;
            
        while(i<j){
            if(digs[i++] != digs[j--]) return false;
        }
        
        return true;
    }
};