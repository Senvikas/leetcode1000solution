class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int n1 = __builtin_popcount(num1);
        int n2 = __builtin_popcount(num2);

        if(n1 == n2) return num1;

        // 1-> 1101, 2-> 1111
       if(n1 < n2){  // start setting bits from left(set least significant bits only)
        int extraBits = n2 - n1;
            for(int i=0; i<=31; i++){
                if(num1 & (1 << i)) continue;
                num1 = num1 | (1 << i);
                extraBits--;
                if(extraBits == 0) return num1;
            }
       }

        // means num1 has more bits
        // 1-> 1111, 2-> 1011, 3 bits int num2 will settle down 3 bits in num1
        // we need to unset the extra bits
       int extraBits = n1 - n2;

        for(int i=0; i<=31; i++)
        {   
            // already unset -> coninue;.
            if(((num1 >> i) & 1) == 0) continue;
            cout << num1 << " ";
            num1 = num1 ^ (1 << i);
            extraBits--;
            cout << num1 << endl;
            if(extraBits == 0) return num1;
        }

        return num1;
    }
};