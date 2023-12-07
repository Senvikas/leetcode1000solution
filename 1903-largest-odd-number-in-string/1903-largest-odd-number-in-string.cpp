class Solution {
public:
    string largestOddNumber(string num) {
        int i = num.length()-1; //1
        for(i; i>=0;i--){
            if((num[i]-0)%2==0)
                num.pop_back();
            else
                return num;
        }
        return num;
    }
};